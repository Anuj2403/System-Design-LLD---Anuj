// Requirements

// 1-> There should be multiple floors on the parking lot.
// 2-> There should be multiple gates on the parking lot.
// 3-> There should be parking attendant at each gate.
// 4->The entry gate should process the parking tickets.
// 5-> The exit gate should process the payment on the hourly basis.
// 6-> The parking lot should have a facility to park different types of vehicle.
// 7-> There should be display boards on each floor to show the vacant floors.

# include <bits/stdc++.h>
using namespace std;

class ParkingLot{
     list<ParkingFloors> parkingFloors;
     list<Entrance> entrances;
     list<Exit> exits;

     Address address; // some meta data of parking lot contaning address and name of parking lot
     string ParkingLotName;

     bool isParkingLotAvailableForVehicle(Vehicle vehicle);
     bool updateParkingAttendant(ParkingAttendant parkingAttendant,int gateId);
};

class ParkingFloors{
     int levelId;
     bool isFull;
     list<ParkingSpaces> parkingSpace;
     ParkingDisplayBoard parkingDisplayBoard;
};

class Gate{
    int gateId;
    ParkingAttendant parkingAttendant;
};

class Entrance : public Gate{
    public:
    ParkingTicket getParkingTicket(Vehicle vehicle);
};

class Exit : public Gate{
    ParkingTicket payForParking(ParkingTicket parkingTicket,Payment payment);
};

class Address{
    string country;
    string state;
    string city;
    string street;
    string pincode;
};

class ParkingSpaces{ 
      int spaceId;
      bool isFree;
      double costPerHour;
      Vehicle vehicle;
      ParkingSpaceTypes parkingSpaceTypes; // It is of type enum which will tell us that whether this space for two-wheeler or four wheeler or truck
};

class ParkingDisplayBoard{
    map<ParkingSpaceTypes,int> FreeSlotsAvailable;
    public:
    void updateFreeSlots(ParkingSpaceTypes parkingSpaceTypes,int spaces);
};

class Account{
    string name;
    string email;
    string address;
    string empId;
    string password;
};

class Admin : public Account{
    public:
    bool addParkingFloors(ParkingLot parkingLot,ParkingFloors parkingFloors);
    bool addParkingSpace(ParkingFloors parkingFloors,ParkingSpaces parkingSpaces);
    bool addParkingDisplayBoard(ParkingFloors parkingFloors,ParkingDisplayBoard parkingDisplayBoard);
};

class ParkingAttendant: public Account{
    Payment paymentService;
    public:
    bool ProcessVehicleEntry(Vehicle vehicle);
    PaymentInfo processPayment(ParkingTicket parkingTicket,PaymentType paymetType);
};

class Vehicle{
    string LicenseNumber;
    VehicleType vehicleType;
    ParkingTicket parkingTicket;
    PaymentInfo paymentInfo;
};

class ParkingTicket{
    int ticketId;
    int levelId;
    int spaceId;
    int VehicleEntryTimeDate;
    int VehicleExitTimeDate;
    double TotalCost;
    ParkingTicketStatus ParkingTicketStatus; // defines whether tickat is paid or not

    public:
    void updateTotalCost();
    void updateVehicleExitTime(int VehicleExitTimeDate);
};

 enum PaymentType{
    CASH,CREDIT_CARD, DEBIT_CARD, UPI
};

enum ParkingSpaceTypes{
    BIKE_PARKING, CAR_PARKING, TRUCK_PARKING
};

enum VehicleType{
    CAR, BIKE, TRUCK
};

enum PaymentStatus{
    UNPAID, PENDING, DECLINED, CANCELLED, REFUNDED, COMPLETED
};

enum ParkingTicketStatus{
     PAID, ACTIVE
};

class Payment{
    public:
    PaymentInfo makePayment(ParkingTicket parkingTicket,PaymentType paymentType);
};

class PaymentInfo{
    double amount;
    int PaymentDate;
    int transactionId;
    ParkingTicket parkingTicket;
    PaymentStatus paymentStatus;
};
