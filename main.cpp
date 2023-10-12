#include <iostream>
#include <chrono>
#include <ctime>
#include <filesystem>
#include "./src/repository/repository.h"

int main(int argc, char* argv[]) {
    RepoInitialization repo;

    if(argc >= 2) {
        std::vector<std::string> allArgs(argv, argv + argc);
        std::string cmdlineFlag = allArgs[1];

        if(cmdlineFlag == "version"){
            std::cout<<"version 1.0.0 alpha" <<std::endl;
        }

        if (cmdlineFlag == "init") {
            RepoInitialization::initRepository();
            repo.setRepositoryName();
            RepositoryMetaData data = repo.getMetaData();
            std::cout<<data.repoName<<" Repo Name \n";
            std::cout<<data.repoHashCode<<" Repo Hashcode \n";
        }



       // std::string filePath = argv[2];
        // std::filesystem::path pathToCheck {filePath};

       // if(!filePath.empty()){
         //   for(auto const& dir_entry : std::filesystem::recursive_directory_iterator{pathToCheck})
           // {
                // std::cout << "directory entry " << dir_entry  << std::endl;
                // std::time_t result = std::time(nullptr);
                //std::cout<< std::asctime(std::localtime(&result));
            //}
        }


    return 0;
}
