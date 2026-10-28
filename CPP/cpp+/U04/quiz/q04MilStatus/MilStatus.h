#ifndef MIL_STATUS_H
#define MIL_STATUS_H

#include<string>
#include<array>
class MilStatus {
private:
  int id;
  std::string name;
  int age;
  int equipNum;
  std::array<std::string, 5> equipments;
  static constexpr std::size_t kMaxEquipments = 5;

  static int clampEquipNum(int num);

  public:
  MilStatus();
  MilStatus(int _id, const std::string &_name, int _age, int _equipNum, const std::array<std::string, 5>& _equipments);

  bool addEquipment(const std::string &item);

  void printStatus() const;
};

#endif