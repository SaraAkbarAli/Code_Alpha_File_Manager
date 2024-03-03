#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <filesystem>

using namespace std;

bool createDirectory(const std::string& folderName) 
{
    if (CreateDirectoryA(folderName.c_str(), nullptr) || GetLastError() == ERROR_ALREADY_EXISTS) 
        return true;
    
    return false;
}

void createFileInDirectory(const std::string& directory, const std::string& fileName,std::string &content)
{
    std::string directoryPath = "C:\\Users\\Sara\\Desktop\\Code_Alpha\\File_Manager\\"+ directory;  //put the path of your file in the pc
    std::string filePath = directoryPath + "\\" + fileName;
    std::ofstream outputFile(filePath);

    if (outputFile.is_open())
    {
        cout << "File created successfully in directory: " << directory << endl;
        outputFile << content;
        outputFile.close();
    }
    else 
    {
        cout << "Unable to create the file in directory: " << directory << endl;
    }   
}

void ReadFile(const std::string &directory,const std::string& inputFile)
{
    std::string directoryPath = "C:\\Users\\Sara\\Desktop\\Code_Alpha\\File_Manager\\" + directory;
    std::string filePath = directoryPath + "\\" + inputFile;
    std::ifstream inputFileStream(filePath);

    if (inputFileStream.is_open())
    {
       cout << "\nContent of the file:\n";

        std::string line;
        while (std::getline(inputFileStream, line)) 
        {
            cout << line << '\n';
        }
        inputFileStream.close();
    }
    else 
    {
        cout << "Unable to open the file for reading.\n";
    }
}

void CopyFile(const string& directory1, const string& directory2, const string& file1, const string& file2)
{
    fstream f1, f2;
    string ch;

    string filePath1 = "C:\\Users\\Sara\\Desktop\\Code_Alpha\\File_Manager\\" + directory1 + "\\" + file1;

    f1.open(filePath1, ios::in);

    if (!f1.is_open()) {
        cout << "Error opening source file: " << filePath1 << endl;
        return;
    }

    string filePath2 = "C:\\Users\\Sara\\Desktop\\Code_Alpha\\File_Manager\\" + directory2 + "\\" + file2;

    f2.open(filePath2, ios::out);

    if (!f2.is_open()) {
        cout << "Error opening destination file: " << filePath2 << endl;
        f1.close();
        return;
    }

    while (getline(f1, ch))
    {
        f2 << ch << endl;
    }

    f1.close();
    f2.close();

    f2.open(filePath2, ios::in);

    while (getline(f2, ch))
    {
        cout << ch << endl;
    }

    f2.close();
}

void MoveFile(const string& sourceDirectory, const string& destinationDirectory, const string& sourceFile, const string& destinationFile)
{
    fstream sourceFileStream, destinationFileStream;
    string line;

    string sourceFilePath = "C:\\Users\\Sara\\Desktop\\Code_Alpha\\File_Manager\\" + sourceDirectory + "\\" + sourceFile;

    sourceFileStream.open(sourceFilePath, ios::in);

    if (!sourceFileStream.is_open()) {
        cout << "Error opening source file: " << sourceFilePath << endl;
        return;
    }

    string destinationFilePath = "C:\\Users\\Sara\\Desktop\\Code_Alpha\\File_Manager\\" + destinationDirectory + "\\" + destinationFile;

    destinationFileStream.open(destinationFilePath, ios::out);

    if (!destinationFileStream.is_open()) {
        cout << "Error opening destination file: " << destinationFilePath << endl;
        sourceFileStream.close();
        return;
    }

    while (getline(sourceFileStream, line))
    {
        destinationFileStream << line << endl;
    }

    sourceFileStream.close();
    destinationFileStream.close();

    if (remove(sourceFilePath.c_str()) != 0) {
        cout << "Error deleting source file: " << sourceFilePath << endl;
    }
    else {
        cout << "File moved successfully." << endl;
    }
}


int main()
{
    int choice;

    do
    {
        cout << "Which operation do you perform: " << endl;
        cout << "1) Create Directory" << endl;
        cout << "2) Create File in a Directory" << endl;
        cout << "3) Read File" << endl;
        cout << "4) Move File" << endl;
        cout << "5) Copy File" << endl;
        cout << "Enter 0 to Exit" << endl;
        cout << "Enter your option" << endl;
        cin >> choice;
        cin.ignore();

        if(choice==1)
        {
            string directory_name;
            cout << "Enter the name of the directory" << endl;
            std::getline(std::cin, directory_name);
            createDirectory(directory_name);
           
        }
        else if(choice ==2)
        {
            string directory_name;
            cout << "Enter the name of the directory" << endl;
            std::getline(std::cin, directory_name);
            string file_name;
            cout << "Enter the name of the file" << endl;
            cin >> file_name;
            std::string content="i am code alpha intern";
            cout << "Enter your content" << endl;
            cin >> content;
            createFileInDirectory(directory_name,file_name,content);
            
        }
        else if (choice == 3)
        {
            string directory_name;
            cout << "Enter the name of the directory" << endl;
            std::getline(std::cin, directory_name);
            string file_name;
            cout << "Enter the name of the file to view: " << endl;
            std::getline(std::cin, file_name);
            ReadFile(directory_name,file_name);
           
        }
        else if (choice == 4)
        {
            string  directory_name1, directory_name2;
            string source_file, destination_file;
            cout << "Enter the name of the directory from where you want to copy the file" << endl;
            std::getline(std::cin, directory_name1);
            cout << "Enter the name of the source file from directory 1: " << endl;
            std::getline(std::cin, source_file);
            cout << "Enter the name of the directory where you want to copy the file" << endl;
            std::getline(std::cin, directory_name2);
            cout << "Enter the name of the destination file: " << endl;
            std::getline(std::cin, destination_file);
            MoveFile(directory_name1, directory_name2, source_file, destination_file);
           
        }
        else if (choice == 5)
        {
            string  directory_name1, directory_name2;
            string source_file, destination_file;
            cout << "Enter the name of the directory from where you want to copy the file" << endl;
            std::getline(std::cin, directory_name1);
            cout << "Enter the name of the source file from directory 1: " << endl;
            std::getline(std::cin, source_file);
            cout << "Enter the name of the directory where you want to copy the file" << endl;
            std::getline(std::cin, directory_name2);
            cout << "Enter the name of the destination file: " << endl;
            std::getline(std::cin, destination_file);
            CopyFile(directory_name1,directory_name2,source_file,destination_file);
            
        }   
    } while (choice != 0);

    return 0;
}