//
// Created by Berke Palamutcu on 11.07.2023.
//

#ifndef TRACKR_REPOSITORY_H
#define TRACKR_REPOSITORY_H

#include <iostream>
#include <filesystem>
#include <functional>

struct RepositoryMetaData {
    std::size_t repoHashCode;
    std::string repoName;
};

namespace fs = std::filesystem;

class RepoInitialization {
    private:
        RepositoryMetaData metaData;
    public:
        void static initRepository() {
            fs::path dir{"/Users/berkepalamutcu/Desktop/projects/.trackR"};
            fs::path versionDir = dir / "versions";
            if(!fs::exists(dir)){
                if(fs::create_directory(dir)){
                    fs::create_directory(versionDir);
                    std::cout << "TrackR initialized with the ";
                } else {
                    std::cout << "Failed to create TrackR instance ";
                }
            } else {
                std::cout << "The TrackR is already initialized\n";
            }
        }

        void setRepositoryName() {
            fs::path currentPath = std::filesystem::current_path();
            std::string folderName = currentPath.filename().string();
            metaData.repoName = folderName;
         }

        [[nodiscard]] RepositoryMetaData getMetaData()const {
                return metaData;
        }

        void generateHashCodeForRepoMetaData() {
            std::hash<std::string> hasher;
            metaData.repoHashCode = hasher(metaData.repoName);
        };
};

#endif //TRACKR_REPOSITORY_H
