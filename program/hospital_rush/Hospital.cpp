#include "Hospital.hpp"

void clear() {
  #ifdef _WIN32 
    system("cls");
  #else 
    system("clear");
  #endif
}

#ifdef __linux__
  char getch() {
      struct termios oldt;
      tcgetattr(STDIN_FILENO, &oldt);
      
      struct termios newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      
      char ch;
      read(STDIN_FILENO, &ch, 1);
      
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      
      return ch;
  }
#endif

void wait() {
  std::cout << "Press enter to continue...";
  getch();
}

uint32_t Hospital::generateRandomTingkatan_(){
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> randomTingkatan(1, 5);
  return randomTingkatan(gen);
}

uint32_t Hospital::generateUniqueId_(){
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> randomUniqueId(111, 999);
  return randomUniqueId(gen);
}

void Hospital::generateDummyPatients_(uint32_t count)
{

  
  std::uniform_int_distribution<> randomUniqeuId(111, 999);

  std::vector<std::string> defaultPatients = {
    "Joshua",
    "Ahmad",
    "Muhammad",
    "Reza",
    "Alex",
    "Juan",
    "Arya",
    "Michael",
    "Abed",
    "Erlan"
  };

  std::cout << "<<Dummy Patient Generator>>" << std::endl;

  for (int i = 0; i < defaultPatients.size(); i++) {
    auto tingkatan = generateRandomTingkatan_();
    auto uniqueId = generateUniqueId_();

    allPatients[tingkatan].emplace_back(uniqueId, defaultPatients[i], tingkatan, allPatients[tingkatan].size());
  }
}

Hospital::Hospital() {
  generateDummyPatients_(10);
}

void Hospital::showMenu_() {
  unsigned short option;
  std::cout << " === Hospital Rush!! ===" << std::endl;
  std::cout << "1. Tambah pasien baru" << std::endl;
  std::cout << "2. Layani pasien berikutnya" << std::endl;
  std::cout << "3. Lihat antrean" << std::endl;
  std::cout << "4. Keluar" << std::endl;
  std::cout << "Pilih menu: ";
  std::cin >> option;

  switch (option) {
    case 1:
      clear();
      addPatient_();
      wait();
      break;
    case 2:
      clear();
      handlePatient_();
      wait();
      break;
    case 3:
      clear();
      showPatients_();
      wait();
      break;
    case 4:
      isRunning_ = false;
      break;
    default: 
      std::cout << "Opsi tidak ada" << std::endl;
  }
}

void Hospital::showPatients_() {
  int index = 0;
  std::cout << "<<Antrian Rumah Sakit>>" << std::endl;
  for (int i = 5; i >= 0; i--) {
    for (auto& patient: allPatients[i]) {
      printf("%d. Pasien %d - %s (Keparahan %d)\n", index, patient.getUniqueId(), patient.getName().c_str(), patient.getTingkatan());
      index++;
    }
  }
}

void Hospital::handlePatient_() {
  int index = 0;
  for (int i = 5; i >= 0; i--) {
    for (int j = 0; j < allPatients[i].size(); j++) {
      if (index == 0) {
        printf("Pasien %d - %s (Keparahan %d) telah dilayani", allPatients[i][j].getUniqueId(), allPatients[i][j].getName().c_str(), allPatients[i][j].getTingkatan());
        allPatients[i].erase(allPatients[i].begin() + j);
      }
      index++;
    }
  }
}

void Hospital::addPatient_() {
  std::string nama;
  uint32_t keparahan;

  std::cout << "Tingkat Keparahan: ";
  std::cin >> keparahan;

  std::cout << "Nama Pasien: ";
  std::cin >> nama;

  allPatients[keparahan].emplace_back(generateUniqueId_(), nama, keparahan, allPatients[keparahan].size());
  std::cout << "Berhasil menambahkan pasien baru." << std::endl;
}

void Hospital::start() {
  while (isRunning_) {
    clear();
    showMenu_();
  }
}
