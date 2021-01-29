#include "codegeneratorutils.hpp"
#include <QStringBuilder>
#include <QStringList>

codeGeneratorUtils::codeGeneratorUtils()
{
    reg = 1;
}

std::string codeGeneratorUtils::generate()
{
    main_text += buffer;
    formatMainText();
    std::string text = "";
    text += "declare i32 @printf(i8*, ...)\n";
    text += "declare i32 @scanf(i8*, ...)\n";
    text += "@strpi = constant [4 x i8] c\"%d\\0A\\00\"\n";
    text += "@strpd = constant [4 x i8] c\"%f\\0A\\00\"\n";
    text += "@strps = constant [4 x i8] c\"%s\\0A\\00\"\n";
    text += "@strsi = constant [3 x i8] c\"%d\\00\"\n";
    text += "@strsd = constant [4 x i8] c\"%lf\\00\"\n";
    text += "\n";
    text += header_text;
    text += "define i32 @main() nounwind {\n";
    text += main_text;
    text += "  ret i32 0\n";
    text += "}\n";
    return text;
}

void codeGeneratorUtils::function_start(std::string id)
{
    main_text += buffer;
    main_reg = reg;
    buffer = "define void @" + id + "() nounwind {\n";
    reg = 1;
}

void codeGeneratorUtils::function_end()
{
    buffer += "ret void\n";
    formatBuffer();
    buffer += "}\n\n";
    header_text += buffer;
    buffer = "";
    reg = main_reg;
}

void codeGeneratorUtils::call(std::string id)
{
    buffer += "call void @" + id + "()\n";
}

void codeGeneratorUtils::print(std::string text)
{
    int str_len = text.size();
    std::string str_type = "[" + std::to_string(str_len + 2) + " x i8]";
    header_text += "@str" + std::to_string(str_i) + " = constant" + str_type + " c\"" + text + "\\0A\\00\"\n";
    buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ( " + str_type + ", " + str_type + "* @str" + std::to_string(str_i) + ", i32 0, i32 0))\n";
    str_i++;
    reg++;
}

void codeGeneratorUtils::printf_i32(std::string id, std::unordered_set<std::string> globalNames)
{
    if(globalNames.find(id) != globalNames.end())
        buffer += "%" + std::to_string(reg) + " = load i32, i32* @" + id + "\n";
    else
        buffer += "%" + std::to_string(reg) + " = load i32, i32* %" + id + "\n";
    reg++;
    buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @strpi, i32 0, i32 0), i32 %" + std::to_string(reg - 1) + ")\n";
    reg++;
}

void codeGeneratorUtils::printf_double(std::string id, std::unordered_set<std::string> globalNames)
{
    if(globalNames.find(id) != globalNames.end())
        buffer += "%" + std::to_string(reg) + " = load double, double* @" + id + "\n";
    else
        buffer += "%" + std::to_string(reg) + " = load double, double* %" + id + "\n";
    reg++;
    buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @strpd, i32 0, i32 0), double %" + std::to_string(reg - 1) + ")\n";
    reg++;
}

void codeGeneratorUtils::printf_string(std::string id, int length, std::unordered_set<std::string> globalNames, std::string function)
{
    if(globalNames.find(id) != globalNames.end())
        buffer += "%" + std::to_string(reg) + " = getelementptr inbounds [" + std::to_string(length + 1) + " x i8], [" + std::to_string(length + 1) + " x i8]* @" + id + ", i32 0, i32 0\n";
    else
        buffer += "%" + std::to_string(reg) + " = getelementptr inbounds [" + std::to_string(length + 1) + " x i8], [" + std::to_string(length + 1) + " x i8]* @" + function + "." + id + ", i32 0, i32 0\n";
    reg++;
    buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @strps, i32 0, i32 0), i8* %" + std::to_string(reg - 1) + ")\n";
    reg++;
}

void codeGeneratorUtils::scanf_i32(std::string id, std::unordered_set<std::string> globalNames)
{
    assign_i32(id, "0", &globalNames);
    if(globalNames.find(id) != globalNames.end())
        buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @strsi, i32 0, i32 0), i32* @" + id + ")\n";
    else
        buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @strsi, i32 0, i32 0), i32* %" + id + ")\n";
    reg++;
}

void codeGeneratorUtils::scnaf_double(std::string id, std::unordered_set<std::string> globalNames)
{
    assign_double(id, "0.0", &globalNames);
    if(globalNames.find(id) != globalNames.end())
        buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @strsd, i32 0, i32 0), double* @" + id + ")\n";
    else
        buffer += "%" + std::to_string(reg) + " = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @strsd, i32 0, i32 0), double* %" + id + ")\n";
    reg++;
}

void codeGeneratorUtils::declare_i32(std::string id, bool global)
{
    if (global)
        header_text += "@" + id + " = global i32 0\n";
    else
        buffer += "%" + id + " = alloca i32\n";
}

void codeGeneratorUtils::declare_double(std::string id, bool global)
{
    if (global)
        header_text += "@" + id + " = global double 0.0\n";
    else
        buffer += "%" + id + " = alloca double\n";
}

void codeGeneratorUtils::assign_i32(std::string id, std::string value, std::unordered_set<std::string> *globalNames)
{
    if(globalNames != nullptr and globalNames->find(id) != globalNames->end())
        buffer += "store i32 " + value + ", i32* @" + id + "\n";
    else
        buffer += "store i32 " + value + ", i32* %" + id + "\n";

}

void codeGeneratorUtils::assign_double(std::string id, std::string value, std::unordered_set<std::string> *globalNames)
{
    if(globalNames != nullptr and globalNames->find(id) != globalNames->end())
        buffer += "store double " + value + ", double* @" + id + "\n";
    else
        buffer += "store double " + value + ", double* %" + id + "\n";
}

void codeGeneratorUtils::assign_string(std::string id, std::string text, bool global, std::string function)
{
    int len = text.size() + 1;
    std::string str_type = "[" + std::to_string(len) + " x i8]";
    if (global)
        header_text += "@" + id + " = constant" + str_type + " c\"" + text + "\\00\"\n";
    else
        header_text += "@" + function + "." + id + " = constant" + str_type + " c\"" + text + "\\00\"\n";
}

void codeGeneratorUtils::add_i32(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = add i32 " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::add_double(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = fadd double " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::mul_i32(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = mul i32 " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::mul_double(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = fmul double " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::sub_i32(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = sub i32 " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::sub_double(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = fsub double " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::dive_i32(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = sdiv i32 " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::dive_double(std::string val1, std::string val2)
{
    buffer += "%" + std::to_string(reg) + " = fdiv double " + val1 + ", " + val2 + "\n";
    reg++;
}

void codeGeneratorUtils::load_i32(std::string id, std::unordered_set<std::string> globalNames)
{
    if(globalNames.find(id) != globalNames.end())
        buffer += "%" + std::to_string(reg) + " = load i32, i32* @" + id + "\n";
    else
        buffer += "%" + std::to_string(reg) + " = load i32, i32* %" + id + "\n";
    reg++;
}

void codeGeneratorUtils::load_double(std::string id, std::unordered_set<std::string> globalNames)
{
    if(globalNames.find(id) != globalNames.end())
        buffer += "%" + std::to_string(reg) + " = load double, double* @" + id + "\n";
    else
        buffer += "%" + std::to_string(reg) + " = load double, double* %" + id + "\n";
    reg++;

}

void codeGeneratorUtils::sitofp(std::string id)
{
    buffer += "%" + std::to_string(reg) + " = sitofp i32 " + id + " to double\n";
    reg++;
}

void codeGeneratorUtils::fptosi(std::string id)
{
    buffer += "%" + std::to_string(reg) + " = fptosi double " + id + " to i32\n";
    reg++;
}

void codeGeneratorUtils::formatBuffer()
{

    QStringList lines = QString::fromStdString(buffer).split("\n");
    QString main = "";
    main = main % lines[0] % "\n";
    for(int i = 1; i< lines.size(); i++)
    {
        main = main % " " % lines[i] % "\n";
    }
    buffer = main.toStdString();
}

void codeGeneratorUtils::formatMainText()
{
    QStringList lines = QString::fromStdString(main_text).split("\n");
    QString main = "";
    for(QString line: lines)
    {
        main = main % " " % line % "\n";
    }
    main_text = main.toStdString();
}
