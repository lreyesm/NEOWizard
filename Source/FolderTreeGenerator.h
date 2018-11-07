#ifndef FOLDERTREEGENERATOR_H
#define FOLDERTREEGENERATOR_H
#include <QtCore>

class FolderTreeGenerator
{
public:
    static void generateFileTree(const QString& pathRef, const QStringList& folderTreeRef);
private:
    FolderTreeGenerator();
    Q_DISABLE_COPY(FolderTreeGenerator)
};

#endif // FOLDERTREEGENERATOR_H
