// #include <conio.h>
#include <string>
#include <iostream>
#include <array>
#include <fstream>
// struct date // дата рождения
//   {char daymon[6];
//    int year;  };
// //=======     class Student    =================
//    class Student{
//    char name[30]; //private
//    date t;
//    char adr[30], fac[20];
//    int kurs;
//      public:
//        Student();
//        char *getfac();
//        int getkurs();
//        void show();
//         };
// Student::Student()
//        {cout<<"Input name:"; cin>>name;
//        cout<<"Input date of born\n";
//        cout<<"Day.mon:";    cin>>t.daymon;
//        cout<<"Year:";       cin>>t.year;
//        cout<<"Input adr:";  cin>>adr;
//        cout<<"Input fac:";  cin>>fac;
//        cout<<"Input kurs:"; cin>>kurs;
// }
// void Student::show()
//     {
//      cout<<"Name      :"<<name<<endl;
//      cout<<"Was born  :"<<t.daymon<<'.'<<t.year<<endl;
//      cout<<"Address    :"<<adr<<endl;
//      cout<<"Fac       :"<<fac<<endl;
//      cout<<"Kurs      :"<<kurs<<endl;
//      }
// char *Student::getfac() { return fac; }
// int Student::getkurs() { return kurs;  }
// void spisfac(Student spis[],int n)//список студентов заданного факультетата
//      {char fac[20];
//       cout<<"Input faculty:";  cin>>fac;
//       for(int i=0;i<n;i++)
//            if(strcmp(spis[i].getfac(),fac)==0)spis[i].show();
//      }
// void spisfackurs(Student spis[],int n)
// //список студентов заданных факультета и курса
//      {int i,k;
//       char fac[20];
//       cout<<"Input faculty:";     cin>>fac;
//       cout<<"Input the course:";  cin>>k;
//       for(i=0;i<n;i++)
//       if ((strcmp(spis[i].getfac(),fac)==0)&&(spis[i].getkurs()==k))
//                spis[i].show();
//      }
// //=========    main   ================
//  void main()
// {    Student *spis;
//      int n;
//      cout<<"Input a number of students: "; cin>>n;
//      spis=new Student [n];
//      for(int i=0;i<n;i++) {
//         cout<<"=============================="<<endl;
//         spis[i].show();
//         }
// spisfac(spis,n);
// spisfackurs(spis,n);
// delete [] spis;
// cout<<"press any key!"
// while(!kbhit());
// }


//===============

struct Date
{
  // const here in order no to get compiler warning
  // warning: ISO C++ forbids converting a string constant to ‘char*’
  // const char *day;
  std::string day;

  int min;
  int hour;
  int month;
  int year;
};

class Train
{
  std::string destination;

  int trainNumber;
  // According to the rw.by carriage classes
  int sittingCoaches;
  int economyClassSleeper;
  int openCarriegeSeats;

  Date departureTime;

public:
  Train(){};
  Train(
    std::string destination,
    int trainNumber,
    int sittingCoaches,
    int economyClassSleeper,
    int openCarriegeSeats
  )
  {
    this->destination = destination;
    this->trainNumber = trainNumber;
    this->sittingCoaches = sittingCoaches;
    this->economyClassSleeper = economyClassSleeper;
    this->openCarriegeSeats = openCarriegeSeats;
  };

  // Getters
  std::string getDestination();

  int getSittingCoaches();
  int getTrainNumber();

  Date getDepartureTime();

  // Setters
  void setDestination(std::string destination);
  void setDepartureTime(std::string day, int min, int hour, int month, int year);
};

// Implementation

// Train::Train(){};

int Train::getTrainNumber()
{
  return this->trainNumber;
}

Date Train::getDepartureTime()
{
  return this->departureTime;
}

std::string Train::getDestination()
{
  return this->destination;
}

int Train::getSittingCoaches()
{
  return this->sittingCoaches;
}

void Train::setDestination(std::string destination)
{
  this->destination = destination;
}

void Train::setDepartureTime(std::string day, int min, int hour, int month, int year )
{
  this->departureTime = {
    day,
    min,
    hour,
    month,
    year
  };
}

// Compile options:
// g++ -g -o a_main main.cpp
int main()
{
  // Date d = { "Mon", 8, 16, 19, 1, 2019 };
  // printf("first: %s, last: %d\n", d.day, d.year);

  Train *trains[5];

  // trains[0] = new Train("Minsk", 33, 0, 50, 80);
  // trains[1] = new Train("Moscow", 34, 100, 50, 80);
  // trains[2] = new Train("Paris", 35, 100, 50, 80);
  // trains[3] = new Train("Berlin", 36, 0, 50, 80);
  // trains[4] = new Train("Minsk", 37, 100, 50, 80);

  std::ifstream infile("trains_in.txt");

  if (infile.is_open())
  {
    std::string line;
    std::string c;
    std::string arg0;
    // std::string delimeter;
    int arg1, arg2, arg3, arg4, arg5;
    int counter = 0;

    while (std::getline(infile, line))
    {
      int last = 0;
      int next = 0;
      std::string delimiter = ",";
      while ((next = line.find(delimiter, last)) != std::string::npos)
      {
        // std::cout << line.substr(last, next-last) << std::endl;
        last = next + 1;
      }
      std::cout << line.substr(last) << std::endl;
      // trains[counter] = new Train(arg0, arg1, arg2, arg3, arg4, arg5)
    }
    infile.close();
  }


  // for (int i = 0; i < 5; i++)
  // {
  //   if (trains[i]->getDestination() == "Minsk")
  //   {
  //     std::cout << "=====" << std::endl;
  //     std::cout << "Destination: Minsk" << std::endl;
  //     std::cout << "Train number: " << trains[i]->getTrainNumber() << std::endl;
  //   }
  // }

  // Date d = { "Mon", 16, 19, 1, 2019 };
  // trains[0]->setDepartureTime("Mon", 1, 23, 1, 2019);
  // trains[1]->setDepartureTime("Wed", 59, 5, 3, 2019);
  // trains[2]->setDepartureTime("Tue", 13, 18, 2, 2019);
  // trains[3]->setDepartureTime("Sun", 26, 9, 12, 2019);
  // trains[4]->setDepartureTime("Mon", 16, 13, 1, 2019);
  // // std::cout << "Date: " << trains[0]->getDepartureTime().day << std::endl;

  // for (int i = 0; i < 5; i++)
  // {
  //   if (trains[i]->getDestination() == "Minsk" && trains[i]->getDepartureTime().hour > 5)
  //   {
  //     std::cout << "=====" << std::endl;
  //     std::cout << "Destination: Minsk, Departure hour > than 5.00" << std::endl;
  //     // std::cout << "Train number: " << trains[i]->getTrainNumber() << trains[i]->getDepartureTime().hour << std::endl;
  //     printf("Train number: %d, Departure hour: %d\n", trains[i]->getTrainNumber(), trains[i]->getDepartureTime().hour);
  //   }
  // }

  // for (int i = 0; i < 5; i++)
  // {
  //   if (trains[i]->getDestination() == "Minsk" && trains[i]->getSittingCoaches() > 0)
  //   {
  //     std::cout << "=====" << std::endl;
  //     std::cout << "Destination: Minsk, Sitting coaches > than 0" << std::endl;
  //     printf("Train number: %d, Number of sitting coaches: %d\n", trains[i]->getTrainNumber(), trains[i]->getSittingCoaches());
  //   }
  // }

  delete[] trains;
  return 0;
};
