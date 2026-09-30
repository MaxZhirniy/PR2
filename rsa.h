#ifndef RSA_H
#define RSA_H
#include <fstream>
#include <string>

void runRsa();
void encryptFileRsa(const std::string inputPath, const char *encryptedPath, int e, int n, std::ofstream &logFile);
void decryptFileRsa(const char *encryptedPath, const char *decryptedPath, int d, int n, std::ofstream &logFile);

#endif