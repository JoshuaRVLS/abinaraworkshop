#include "Shop.hpp"
#include <string>
#include <cstdlib>
#ifdef _WIN32
  #include <conio.h>
#else 
  #include <termios.h>
  #include <unistd.h>
#endif

void Shop::clear_() {
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



void Shop::wait_()
{
  std::cout << "\nPress enter to continue...";
  getch();
}

void Shop::showMenu_()
{
  unsigned short option;

  std::cout << "=== Abinaramart System ===" << std::endl; 
  std::cout << "1. Tambah barang" << std::endl;
  std::cout << "2. Lihat daftar barang" << std::endl;
  std::cout << "3. Total harga semua barang" << std::endl;
  std::cout << "4. Beli barang" << std::endl;
  std::cout << "5. Keluar" << std::endl;
  
  std::cout << "Pilih Menu: ";
  std::cin >> option;

  switch(option) {
    case 1:
      this->clear_();
      this->addProduct_();
      this->wait_();
      break;
    case 2:
      this->clear_();
      this->showProducts_();
      this->wait_();
      break;
    case 3:
      this->clear_();
      this->showTotalProducts_();
      this->wait_();
      break;
    case 4:
      this->clear_();
      uint32_t productIndex;
      std::cout << "Masukan produk yang ingin anda beli: ";
      std::cin >> productIndex;
      this->buyProduct_(productIndex);
      this->wait_();
      break;
    case 5:
      std::cout << "Terima kasih sudah menggunakan sistem Abinaramart!" << std::endl;
      this->isRunning_ = false;
      break;
    default:
      std::cout << "Opsi tidak ada!" << std::endl;
      this->wait_();
      break;
  }
}

void Shop::addProduct_() {
  std::string productName;
  uint32_t productPrice;
  
  std::cout << "Masukan nama barang: ";
  std::cin >> productName; 

  std::cout << "Masukan harga barang: Rp";
  std::cin >> productPrice;

  this->products_.push_back(Product(products_.size(), productName, productPrice));

  std::cout << "Barang berhasil ditambahkan!" << std::endl;
}

void Shop::showProducts_() {

  std::cout << "Daftar barang di rak: " << std::endl;
  if (!products_.size()) {
    std::cout << "Belum ada produk." << std::endl;
  } else {
  
    for (Product& product: this->products_) {
      printf("%d. %s - Rp%.f\n", product.getId(), product.getProductName().c_str(), product.getProductPrice());
    }
  }
}

void Shop::showTotalProducts_() {
  int totalPrice = 0;

  if (!products_.size()) {
    std::cout << "Belum ada produk." << std::endl;
  } else {
    for (Product& product: products_) {
      totalPrice += product.getProductPrice();
    }
    std::cout << "Total harga semua barang: " << totalPrice;
  } 
}

void Shop::buyProduct_(const int &productIndex) {
  auto productName = products_[productIndex].getProductName().c_str();
  auto productPrice = products_[productIndex].getProductPrice();
  printf("Anda membeli %s(Rp%.f)", productName, productPrice);
}

void Shop::start() {
  while (this->isRunning_) {
    // Ngecek apakah ada di symbol ini di os kalian
    this->clear_();
    this->showMenu_();
  }
}
