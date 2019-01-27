#include <string>
#include <iostream>
#include <array>
#include <fstream>
#include <stdexcept>

struct Date
{
  int day;
  int min;
  int hour;
  int month;
  int year;
};

class Train
{
public:
  std::string destination;

  int trainNumber;
  // According to the rw.by carriage classes
  int sittingCoaches;
  int economyClassSleeper;
  int openCarriegeSeats;

  Date departureTime;

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
  void setDepartureTime(int day, int min, int hour, int month, int year);
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

void Train::setDepartureTime(int day, int min, int hour, int month, int year )
{
  this->departureTime = {
    day,
    min,
    hour,
    month,
    year
  };
}

std::ostream &operator<<(std::ostream &stream, Date date){
  stream << " Day: " << date.day;
  stream << ", Time: " << date.hour << ":" << date.min;
  stream << ", Month: " << date.month;
  stream << ", Year: " << date.year;
  return stream;
}

std::istream &operator>>(std::istream &stream, Date &date){
  std::cout << "Enter Day: " << std::endl;
  stream >> date.day;

  std::cout << "Enter Hour: " << std::endl;
  stream >> date.hour;
  if(date.hour > 23 || date.hour < 0)
  {
    throw std::invalid_argument("received invalid hour");
  }

  std::cout << "Enter Minutes: " << std::endl;
  stream >> date.min;

  std::cout << "Enter Month: " << std::endl;
  stream >> date.month;

  std::cout << "Enter Year: " << std::endl;
  stream >> date.year;
  return stream;
}


std::ostream &operator<<(std::ostream &stream, Train train)
{
  stream << " Train destination: " << train.destination;
  stream << ", Number: " << train.trainNumber;
  stream << ", Sitting coaches: " << train.sittingCoaches;
  stream << ", Economy class sleeper: " << train.economyClassSleeper;
  stream << ", Open carriege seats: " << train.openCarriegeSeats;
  return stream;
}

std::istream &operator>>(std::istream &stream, Train &train)
{
  std::cout << "Enter destination: " << std::endl;
  stream >> train.destination;

  std::cout << "Enter train number: " << std::endl;
  stream >> train.trainNumber;

  std::cout << "Enter sitting coaches: " << std::endl;
  stream >> train.sittingCoaches;

  std::cout << "Enter economy class sleeper: " << std::endl;
  stream >> train.economyClassSleeper;

  std::cout << "Enter open carriege seats: " << std::endl;
  stream >> train.openCarriegeSeats;
  return stream;
}

void trainsGoTo(Train *trains, int trainsSize)
{
  std::string destination;
  std::cout << "Enter train destination: " << std::endl;
  std::cin >> destination;

  std::ofstream fout;
  fout.open("trains_out.txt");
  if (!fout) {
    std::cerr << "Error in opening the output file" << std::endl;
  }

  for (int i = 0; i < trainsSize; i++)
  {
    if (trains[i].getDestination() == destination)
    {
      std::cout << "=====" << std::endl;
      std::cout << "Destination: " << destination << std::endl;
      std::cout << "Train number: " << trains[i].getTrainNumber() << std::endl;
      fout << "=====" << std::endl;
      fout << "Destination: " << destination << std::endl;
      fout << "Train number: " << trains[i].getTrainNumber() << std::endl;
    }
  }
  fout.close();
}

void trainsGoToWithTime(Train *trains, int trainsSize)
{
  std::string destination;
  int hour;
  std::cout << "Enter train destination: " << std::endl;
  std::cin >> destination;
  std::cout << "Enter hour: " << std::endl;
  std::cin >> hour;

  std::ofstream fout;
  fout.open("trains_out.txt");
  if (!fout) {
    std::cerr << "Error in opening the output file" << std::endl;
  }


  for (int i = 0; i < trainsSize; i++)
  {
    if (trains[i].getDestination() == destination && trains[i].departureTime.hour > hour)
    {
      std::cout << "=====" << std::endl;
      std::cout << "Destination: " << destination << std::endl;
      std::cout << "Train number: " << trains[i].getTrainNumber() << std::endl;
      fout << "=====" << std::endl;
      fout << "Destination: " << destination << std::endl;
      fout << "Train number: " << trains[i].getTrainNumber() << std::endl;
    }
  }
  fout.close();
}

void trainsWithSeats(Train *trains, int trainsSize)
{
  std::string destination;
  std::cout << "Enter train destination: " << std::endl;
  std::cin >> destination;

  std::ofstream fout;
  fout.open("trains_out.txt");
  if (!fout) {
    std::cerr << "Error in opening the output file" << std::endl;
  }


  for (int i = 0; i < trainsSize; i++)
  {
    if (trains[i].getDestination() == destination && trains[i].openCarriegeSeats > 0)
    {
      std::cout << "=====" << std::endl;
      std::cout << "Destination: " << destination << std::endl;
      std::cout << "Train number: " << trains[i].getTrainNumber() << std::endl;
      fout << "=====" << std::endl;
      fout << "Destination: " << destination << std::endl;
      fout << "Train number: " << trains[i].getTrainNumber() << std::endl;
    }
  }
  fout.close();
}

void writeTo(Train *trains, int trainsSize)
{
  std::ofstream fout;
  fout.open("trains_out.txt");
  if (!fout) {
    std::cerr << "Error in opening the output file" << std::endl;
  }

  for (int i = 0; i < trainsSize; i++)
  {
    std::cout << trains[i] << std::endl;
    fout << trains[i] << std::endl;
  }
  fout.close();
}

// Compile options:
// g++ -g -o a_main main.cpp
int main()
{
  // Date d = { "Mon", 8, 16, 19, 1, 2019 };
  // printf("first: %s, last: %d\n", d.day, d.year);

  std::ifstream fin;
  fin.open("trains_in.txt");
  if (!fin)
  {
      std::cerr << "Error in opening the file" << std::endl;
      return 1;
  }

  // Determine file line number
  std::string line;
  int trainsSize = 0;
  while(std::getline(fin, line))
  {
    trainsSize += 1;
  }
  fin.clear();
  fin.seekg(0, std::iostream::beg);

  // Create array of objects
  Train trains[trainsSize];
  int trainCounter = 0;
  while (trainCounter < trainsSize)
  {
    Train t;
    Date d;

    fin >> d.day >> d.hour >> d.min >> d.month >> d.year >> t.destination >> t.trainNumber >> t.sittingCoaches >> t.economyClassSleeper >> t.openCarriegeSeats;
    t.departureTime = d;
    std::cout << t.departureTime;
    trains[trainCounter] = t;
    trainCounter += 1;
  }
  fin.close();

  writeTo(trains, trainsSize);

  // trainsGoTo(trains, trainsSize);
  trainsGoToWithTime(trains, trainsSize);
  // trainsWithSeats(trains, trainsSize);

  return 0;
};
