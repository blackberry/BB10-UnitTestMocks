/*
   Copyright 2013 Research In Motion Limited

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef BB_CASCADES_PICKERS_FILEPICKER_HPP
#define BB_CASCADES_PICKERS_FILEPICKER_HPP
#include "gtest/gtest.h"
#include <bb/cascades/pickers/FileType>
#include <bb/cascades/pickers/FilePickerSortFlag>
#include <bb/cascades/pickers/FilePickerViewMode>
#include <bb/cascades/pickers/FilePickerSortOrder>
#include <bb/cascades/pickers/FilePickerMode>
#include <bb/cascades/pickers/Global>
#include <bb/system/SecurityPerimeter>
#include <QObject>
#include <QFlags>
#include <QtDeclarative>
namespace bb {
namespace cascades {
namespace pickers {
class FilePickerPrivate;
class QT_CASCADES_EXPORT BB_CASCADES_PICKERS_EXPORT FilePicker : public QObject
{
public:
    FilePicker(QObject* parent = 0);
    FilePicker(FileType::Types fileType, FileType::Types defaultFileType = 0, const QStringList& filterList = QStringList(), const QStringList& directories = QStringList(), const QStringList& defaultSaveFileNames = QStringList(), QObject* parent = 0);
    virtual ~FilePicker();
    MOCK_METHOD0(open, void ());
    MOCK_METHOD1(setMode, void (bb::cascades::pickers::FilePickerMode::Type mode));
    MOCK_CONST_METHOD0(mode, bb::cascades::pickers::FilePickerMode::Type ());
    MOCK_METHOD1(setTitle, void (const QString& title));
    MOCK_CONST_METHOD0(title, QString ());
    MOCK_METHOD1(setDefaultSaveFileNames, void (const QStringList& defaultSaveNames));
    MOCK_CONST_METHOD0(defaultSaveFileNames, QStringList ());
    MOCK_CONST_METHOD0(allowOverwrite, bool ());
    MOCK_METHOD1(setAllowOverwrite, void (bool overwrite));
    MOCK_METHOD1(setDirectories, void (const QStringList& directories));
    MOCK_CONST_METHOD0(directories, QStringList ());
    MOCK_METHOD1(setType, void (bb::cascades::pickers::FileType::Types fileType));
    MOCK_CONST_METHOD0(type, bb::cascades::pickers::FileType::Types ());
    MOCK_METHOD1(setDefaultType, void (bb::cascades::pickers::FileType::Types fileType));
    MOCK_CONST_METHOD0(defaultType, bb::cascades::pickers::FileType::Types ());
    MOCK_METHOD1(setFilter, void (const QStringList& filter));
    MOCK_CONST_METHOD0(filter, QStringList ());
    MOCK_METHOD1(setViewMode, void (bb::cascades::pickers::FilePickerViewMode::Type mode));
    MOCK_CONST_METHOD0(viewMode, bb::cascades::pickers::FilePickerViewMode::Type ());
    MOCK_METHOD1(setSortBy, void (bb::cascades::pickers::FilePickerSortFlag::Type sortBy));
    MOCK_CONST_METHOD0(sortBy, bb::cascades::pickers::FilePickerSortFlag::Type ());
    MOCK_METHOD1(setSortOrder, void (bb::cascades::pickers::FilePickerSortOrder::Type order));
    MOCK_CONST_METHOD0(sortOrder, bb::cascades::pickers::FilePickerSortOrder::Type ());
    MOCK_METHOD1(setImageCropEnabled, void (bool imageCrop));
    MOCK_CONST_METHOD0(isImageCropEnabled, bool ());
    MOCK_METHOD1(setPerimeter, void (bb::system::SecurityPerimeter::Type perimeter));
    MOCK_CONST_METHOD0(perimeter, bb::system::SecurityPerimeter::Type ());
    MOCK_METHOD0(selectedFiles, QStringList ());
    MOCK_METHOD0(close, void ());
    MOCK_METHOD1(fileSelected, void (const QStringList& selectedFiles));
    MOCK_METHOD0(canceled, void ());
    MOCK_METHOD0(pickerOpened, void ());
    MOCK_METHOD0(pickerClosed, void ());
    MOCK_METHOD1(modeChanged, void (bb::cascades::pickers::FilePickerMode::Type newMode));
    MOCK_METHOD1(typeChanged, void (bb::cascades::pickers::FileType::Types newType));
    MOCK_METHOD1(defaultTypeChanged, void (bb::cascades::pickers::FileType::Types newDefaultType));
    MOCK_METHOD1(titleChanged, void (const QString& newTitle));
    MOCK_METHOD1(defaultSaveFileNamesChanged, void (const QStringList& newSaveFileName));
    MOCK_METHOD1(allowOverwriteChanged, void (bool allowOverwrite));
    MOCK_METHOD1(directoriesChanged, void (const QStringList& newDirectories));
    MOCK_METHOD1(filterChanged, void (const QStringList& newFilter));
    MOCK_METHOD1(viewModeChanged, void (bb::cascades::pickers::FilePickerViewMode::Type newViewMode));
    MOCK_METHOD1(sortByChanged, void (bb::cascades::pickers::FilePickerSortFlag::Type newSortBy));
    MOCK_METHOD1(sortOrderChanged, void (bb::cascades::pickers::FilePickerSortOrder::Type newSortOrder));
    MOCK_METHOD1(imageCropEnabledChanged, void (bool enable));
    MOCK_METHOD1(perimeterChanged, void (bb::system::SecurityPerimeter::Type perimeter));
};
}  
} 
} 
#endif 
