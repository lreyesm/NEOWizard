#include "FolderTreeGenerator.h"


void FolderTreeGenerator::generateFileTree(const QString &pathRef, const QStringList &folderTreeRef)
{
    QDir projectDir(pathRef);
    foreach (const QString &dir, folderTreeRef) {
        if (!projectDir.exists(dir)) { // don't overwrite existing folders
            if (!projectDir.mkdir(dir)) {
                qDebug() << "Error creating directory: " <<  dir;
            }
        }
    }
}
