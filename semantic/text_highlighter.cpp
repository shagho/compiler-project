#include "text_highlighter.hpp"


text_highlighter::text_highlighter(QTextDocument *parent)
    :QSyntaxHighlighter (parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bstring\\b" << "\\btype\\b" << "\\bconst\\b"
                    << "\\bfloat\\b" << "\\bbool\\b" << "\\bint\\b" << "\\bnil\\b"
                    << "\\bsuper\\b";
    foreach (const QString &pattern, keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat1.setForeground(Qt::darkYellow);
    keywordFormat1.setFontWeight(QFont::Bold);
    keywordPatterns.clear();
    keywordPatterns << "\\bfunction\\b" << "\\btrue\\b" << "\\bfalse\\b"
                    << "\\bfor\\b" << "\\bwhile\\b"  << "\\bpublic\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bscaseof\\b"
                    << "\\bswitch\\b" << "\\bcontinue\\b" << "\\bbreak\\b"
                    << "\\bdefault\\b" << "\\bdestruct\\b" << "\\bthis\\b"
                    << "\\bif\\b" << "\\belse\\b" << "\\ballocate\\b";
    foreach (const QString &pattern, keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat1;
        highlightingRules.append(rule);
    }

    multiLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression("\\$\\$[\\s\\S]*\\$\\$");
    rule.format = multiLineCommentFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression("\'.*\'");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegularExpression("\\$\\$");
    commentEndExpression = QRegularExpression("\\$\\$");
}

void text_highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules)
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);


    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

//    while (startIndex >= 0)
//    {
//        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
//        int endIndex = match.capturedStart();
//        int commentLength = 0;
//        if (endIndex == -1) {
//            setCurrentBlockState(1);
//            commentLength = text.length() - startIndex;
//        } else {
//            commentLength = endIndex - startIndex
//                            + match.capturedLength();
//        }
//        setFormat(startIndex, commentLength, multiLineCommentFormat);
//        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
//    }
}
