pragma solidity ^0.8.26;

contract StudentData{

    struct Student{
        uint id;
        string name;
        uint marks;
    }

    Student [] public students;
    uint currentID = 1;

    function addStudent(string memory name, uint marks) public {
        Student memory newStudent = Student(currentID, name, marks);
        students.push(newStudent);
        currentID += 1;
    }

    function getStudentCount() public view returns (uint) {
        return currentID-1;
    }

}