#pragma once
#include <iostream>
#include <string>

enum Permission{
	Admin,
	Minister,
	Common
};

std::string Login(std::wstring account, std::wstring password);
std::string Register(std::wstring account, std::wstring password, std::wstring email, std::wstring CheckCode);
std::string Get(std::wstring account, std::wstring password, std::wstring email, std::wstring CheckCode);
void GeneratCheckCode();