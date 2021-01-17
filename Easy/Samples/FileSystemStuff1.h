#pragma once

#include "../Easy.h"
#include "../Basic/Utilities.h"
#include "../Foundation/CString.h"
#include "../FileSystem/File.h"
#include "../FileSystem/DirectoryService.h"
#include "../Foundation/Number.h"
#include "Helpers/SampleTest.h"
#include "Data/SimpleNumbersSample.h"

namespace easy {
    namespace samples {
        struct FileSystemStuff1: SampleTest {
            bool performAll() {
                fsBasicChecks();
                createAndReadFile1();
                createAndReadFile2();
                readFileAttributes1();
                readDiskStuff();
                tempFileStuff1();
                dirStuff1();
                dirStuff2();
                return true;
            }

            void fsBasicChecks() {
                printLine("fsBasicChecks()");

                using namespace fs;

                Path rootPath = Path::fileFromAbsolutePath("C:\\");
                printLine("path %s must be root: %d", rootPath.absolute().buffer(), rootPath.isRoot());

                rootPath = Path::fileFromAbsolutePath("C:");
                printLine("path %s must be root: %d", rootPath.absolute().buffer(), rootPath.isRoot());

                Path someFile1 = Path::fileFromLocalPath("test.txt");
                printLine("path %s must be not be root: %d", someFile1.absolute().buffer(), someFile1.isRoot());

                Path someDir1 = Path::fileFromAbsolutePath("C:\\Users\\");
                printLine("path %s must be not be root: %d", someDir1.absolute().buffer(), someDir1.isRoot());

                auto someDir1Parent = someDir1.parentPath();
                printLine("path %s parent must be root: %d", someDir1.absolute().buffer(), someDir1Parent.isRoot());

                Path someDir2 = Path::fileFromAbsolutePath("C:\\Users");
                printLine("path %s must be not be root: %d", someDir2.absolute().buffer(), someDir2.isRoot());

                auto someDir2Parent = someDir2.parentPath();
                printLine("path %s parent must be root: %d", someDir2.absolute().buffer(), someDir2Parent.isRoot());
            }

            void createAndReadFile1() {
                printLine("createAndReadFile1()");

                using namespace fs;

                auto path = Path::fileFromLocalPath("\\testFolder\\abc\\test.txt");
                File file = File::createFromPath(path);

                FileOpenFlags flags = FileOpenFlags::writeOverride();

                printLine("Creating and opening file path '%s'....", path.absolute().buffer());

                auto error = file.open(flags);

                if (error != NULL) {
                    printLine("failed to open file, error: %s", error->message.buffer());
                    return;
                }

                BytesBuffer buffer;

                printLine("Success! File name is: %s", path.lastComponent().buffer());

                FileOutputStream* outputStream = file.outputStream();

                CString testText = CString::format("%s (%d)", "write me to file", math::Random().integerValue(0, 100));
                buffer.setSizeInBytes(testText.length());

                for (int e = 0; e < testText.length(); e++) {
                    buffer[e] = testText[e];
                }

                printLine("Writing stuff to file...: %s", testText.buffer());
                
                outputStream->write(buffer);
                outputStream->flush();

                printLine("Success! Reading contents now...");

                FileInputStream* readStream = file.inputStream();

                size_t maxSize = 10000;
                readStream->readAll(buffer, maxSize);

                CString contents = CString::createFromUTF8Bytes(buffer.getBuffer(), buffer.sizeInBytes());

                printLine("contents: %s", contents.buffer());

                printLine("Closing file.");

                file.close();
            }

            void createAndReadFile2() {
                printLine("createAndReadFile2()");

            }

            void readFileAttributes1() {
                printLine("readFileAttributes1()");
                
                using namespace fs;

                printLine("printing the attributes, of each file, in the apps directory");

                auto path = DirectoryService::standard().applicationDirectory();
                Directory dir = Directory::fromPath(path);

                List<Path> paths = dir.contents();
                Dictionary<Path, FileAttributes> attributes = FileAttributeService::standard().readInfos(paths);

                for (auto it = attributes.beginEnumeration(); it.hasNext(); it++) {
                    auto entry = it.get();
                    Path path = entry.first;
                    FileAttributes attrs = entry.second;

                    printLine("%s", path.absolute().buffer());
                    printLine("size: %.1f MB", attrs.size.inMB());
                    printLine("isDirectory: %d", attrs.isDirectory);
                    printLine("isReadonly: %d", attrs.isReadonly);
                    printLine("isHidden: %d", attrs.isHidden);
                }
            }

            void readDiskStuff() {
                printLine("readDiskStuff()");

                auto& dirService = fs::DirectoryService::standard();
                auto appPath = dirService.applicationDirectory();

                printLine("current app path: %s", appPath.absolute().buffer());
                printLine("hard disk total size: %.2f GB", dirService.parentDiskTotalSize(appPath).inGB());
                printLine("hard disk free size: %.2f GB", dirService.parentDiskFreeSize(appPath).inGB());
            }

            void tempFileStuff1() {
                printLine("tempFileStuff1()");

                fs::Path tempFilePath1 = fs::Path::temporaryFilePath();
                printLine("auto generated temp file path 1: %s", tempFilePath1.absolute().buffer());

                fs::Path tempFilePath2 = fs::Path::temporaryFilePath("ez");
                printLine("auto generated temp file path 2: %s", tempFilePath2.absolute().buffer());
            }

            void dirStuff1() {
                printLine("dirStuff1()");

                const fs::Error* error;

                auto path = fs::Path::directoryFromLocalPath("\\testFolder\\cba");
                fs::Directory dir = fs::Directory::fromPath(path);

                error = dir.create();
                printLine("create dir '%s' %s", path.absolute().buffer(), error == nullptr ? "success" : "failure");

                system::sleep(0.5);

                error = dir.remove();
                printLine("delete dir '%s' %s", path.absolute().buffer(), error == nullptr ? "success" : "failure");
            }

            void dirStuff2() {
                printLine("dirStuff2()");

                auto path = fs::DirectoryService::standard().applicationDirectory();
                fs::Directory dir1 = fs::Directory::fromPath(path);

                printLine("application dir '%s' contents: %s", path.absolute().buffer(), dir1.contents().toString().buffer());
            }
        };
    }
};
