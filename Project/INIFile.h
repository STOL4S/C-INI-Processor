#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>

#define E_INI_FILE_BAD_TYPE _HRESULT_TYPEDEF_(0x30000000L)
#define E_INI_FILE_BAD_PATH _HRESULT_TYPEDEF_(0x30000001L)
#define E_INI_FILE_BAD_STREAM _HRESULT_TYPEDEF_(0x30000002L)

#define E_INI_DATA_INVALID_NAME _HRESULT_TYPEDEF_(0x31000000L)
#define E_INI_DATA_INVALID_MEMORY _HRESULT_TYPEDEF_(0x31000001L)
#define E_INI_DATA_UNEXPECTED_VALUE _HRESULT_TYPEDEF_(0x31000002L)

/// <summary>
/// DATA STRUCTURE CLASS FOR THE .INI FILE TYPE
/// THAT HOLDS INFORMATION ON ALL VARIABLES AND
/// HEADERS STORED IN THE FILE. THE FILE CAN
/// EITHER BE LOADED FROM A PATH OR CREATED
/// IN MEMORY FIRST AND THEN SAVED A TO FILE.
/// </summary>
class INIFile
{
	public:
		//DEFAULT CONSTRUCTOR
		//CREATES NULL FILE
		INIFile();

		//CONSTRUCTOR LOADS INI FILE FROM PATH
		//FILE MUST END IN .INI FILE IT TO LOAD
		INIFile(const char* _Path);

		//CONSTRUCTOR LOADS INI FILE FROM PATH
		//FILE MUST END IN .INI FILE IT TO LOAD
		INIFile(std::string _Path);

		//CONSTRUCTOR CREATES INI FILE IN MEMORY
		//USING A SINGLE MAP OF TWO STRING VALUES
		INIFile(std::map<std::string, std::string> _VALUES);

		//DECONSTRUCTOR RELEASES INI VALUES
		//FROM MEMORY RESOURCES
		~INIFile();
		
		//GET BOOL VALUE BY NAME
		HRESULT GetValueByName(std::string Name, bool& _Out);

		//GET INT VALUE BY NAME
		HRESULT GetValueByName(std::string Name, int& _Out);

		//GET FLOAT VALUE BY NAME
		HRESULT GetValueByName(std::string Name, float& _Out);

		//GET LONG VALUE BY NAME
		HRESULT GetValueByName(std::string Name, long& _Out);

		//GET DWORD VALUE BY NAME
		HRESULT GetValueByName(std::string Name, DWORD& _Out);

		//GET CONST CHAR* VALUE BY NAME
		HRESULT GetValueByName(std::string Name, const char*& _Out);

		//GET STRING VALUE BY NAME
		HRESULT GetValueByName(std::string Name, std::string& _Out);

		//RETURNS A STRING REPRESENTING
		//THE FILE PATH RELATIVE TO THE
		//CURRENT WORKING DIRECTORY
		HRESULT GetRelativeFilePath(std::string& _Path);

		//RETURNS A STRING REPRESENTING
		//THE FULL PATH TO THE FILE
		HRESULT GetFullFilePath(std::string& _Path);

		//SAVE TO ORIGINAL PATH
		HRESULT Save();

		//SAVE TO SPECIFIED PATH
		HRESULT Save(std::string _Path);

		//RETURNS A STRING REPRESENTING
		//THE FULL FILE FOR THIS DATA
		HRESULT ToString(std::string& _Out);

	private:
		//VALIDATES THE PATH OF AN INI FILE
		//TO CONFIRM IT HAS THE CORRECT FILE
		//TYPE AND THAT THE FILE PATH IS VALID
		HRESULT ValidateINIFile(std::string _Path);

		//READS ALL DATA VALUES FROM AN INI FILE
		//AT THE SPECIFIED PATH AND LOADS THEM
		//INTO THE VALUES VARIABLE OF THIS CLASS
		HRESULT LoadINIFileData(std::string _Path);

		//PRIVATE FUNCTION THAT SEARCHES FOR THE VALUE
		//USING THE PROVIDED NAME
		HRESULT GetValue(std::string Name, std::string& _Out);

		//ALL DATA VALUES STORED IN THE INI
		//FIRST PARAMETER IS NAME, SECOND
		//PARAMETER IS VALUE
		std::map<std::string, std::string> VALUES;

		//ALL HEADER DATA STORED IN THE INI
		//FIRST PARAMETER IS NAME, SECOND
		//PARAMETER IS INDEX
		std::map<std::string, int> HEADERS;

		//ORIGINAL PATH THE FILE
		//WAS LOADED FROM
		std::string PATH;
};