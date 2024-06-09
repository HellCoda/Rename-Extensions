#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
if (argc < 4) {
std::cout << "Usage: " << argv[0] << " <chemin_dossier> <ancienne_extension> <nouvelle_extension>" << std::endl;
return 1;
}

std::string cheminDossier = argv[1]; // Le chemin du dossier est passé en argument
std::string ancienneExtension = argv[2]; // L'ancienne extension est passée en argument
std::string nouvelleExtension = argv[3]; // La nouvelle extension est passée en argument

for (const auto& entry : fs::directory_iterator(cheminDossier)) {
fs::path filePath = entry.path();
if (filePath.extension() == ancienneExtension) {
fs::path newFilePath = filePath;
newFilePath.replace_extension(nouvelleExtension);
fs::rename(filePath, newFilePath);
}
}

std::cout << "Renommage des extensions termine." << std::endl;
return 0;
}