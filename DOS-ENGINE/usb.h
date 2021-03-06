// SWAMI KARUPPASWAMI THUNNAI
#pragma once

#include<iostream>
#include<string>
#include<set>
#include<map>
#include"autorun.h"

// This is specifically designed to scan the USB drives
// definition for the individual methods is given at the definition

template<typename usb>
class USBScan
{
private:
	std::string drive_letter;
	std::map<usb,std::string> files_scaned_for_pc; // files to be scanned the same in PC
	std::map<usb, std::string> malicious_files; //files identified as malware
	std::map<usb, std::string> semi_malicious_files; // files found to be packed
	std::map<usb,std::string> suspected_files; // files which are suspected to have malware
	Autorun<usb> autoruns;
public:
	bool initialize(std::string drive);
	bool scan(const wchar_t* sDir);
	bool check_in_database(std::string hash);
	void show_malicious_files();
	void show_semi_malicious_files();
	void show_files_scanned_in_pc();
};
