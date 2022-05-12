// Binary Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

struct LibraryRecord
{
    char callNumber[12];
    char title[64];
    char author[32];
    int status;
};

//OPEN library.dat
//IF library.dat is foundand opened THEN
//READ the binary data into an array from library.datand THEN close the file
//ELSE
//OPEN library.txt
//IF library.txt is not found and opened THEN
//PRINT an error messageand exit the program
//ELSE
//READ the text file into the arrayand then close the text file
//CREATEand open the binary file library.dat
//WRITE the contents of your library records array to the binary file then close the file

LibraryRecord getRecordAtIndex(const char* filename, int index)
{
    std::fstream file;
    file.open("library.dat", std::ios::in | std::ios::binary);

    int recordCount;
    file.read((char*)&recordCount, sizeof(int));

    if (index > 0 && index < recordCount)
    {            
        file.seekg(index * sizeof(LibraryRecord), std::ios::cur);     
        LibraryRecord record;
        file.read((char*)&record, sizeof(LibraryRecord));
        return record;
    }

    file.close();
    return LibraryRecord{};
}

int main()
{
    std::fstream file;
    file.open("library.dat", std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        int recordCount;
        file.read((char*)&recordCount, sizeof(int));

        LibraryRecord* records = new LibraryRecord[recordCount];
        file.read((char*)&records, sizeof(LibraryRecord) * recordCount);
        // Do something
        delete[] records;
        file.close();

        LibraryRecord r = getRecordAtIndex("library,dat", 1);
    }
    else
    {
        std::fstream textfile;
        textfile.open("library.txt", std::ios::in);

        if (textfile.is_open() == false)
        {
            std::cout << "Unable to open library text file" << std::endl;
        }
        else
        {
            std::vector<LibraryRecord> records;
            while (!textfile.eof() && textfile.peek() != std::ios::eofbit)
            {
                LibraryRecord record;
                textfile.getline(record.callNumber, 12);
                textfile.getline(record.title, 64);
                textfile.getline(record.author, 32);
                char status[8];
                textfile.getline(status, 8);
                record.status = std::atoi(status);
                records.push_back(record);

            }
            file.open("library.dat", std::ios::out | std::ios::binary);
            if (file.is_open() == false)
            {
            std::cout << "Unable to create library dat file\n";
            }
            else
            {
                int recordCount = records.size();
                file.write((char*)&recordCount, sizeof(int));
                file.write((char*)records.data(), sizeof(LibraryRecord) * recordCount);
                file.close();

            }
        }
    }
}
