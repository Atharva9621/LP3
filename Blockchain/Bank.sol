// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract Bank{

    address public accHolder;
    uint256 balance = 0;

    constructor(){
        accHolder = msg.sender;
    }

    modifier onlyAccountHolder(){
        require(accHolder==msg.sender, "Only the account holder can deposit amount");
        _;
    }

    function showBalance() public view returns (uint){
        return balance;
    }

    function deposit() public payable onlyAccountHolder{
        uint amount = msg.value;
        
        require(amount>0, "Amount to be Deposited must be greater than 0.");
        balance += amount;
    }

    function withdraw(uint256 amount) payable public onlyAccountHolder{
        require(amount>0, "Amount to be withdrawn must be greater than 0");
        require(balance>amount, "You do not have sufficient balance");
        payable(accHolder).transfer(amount);
        balance -= amount;
    }

    receive() external payable{
        balance += msg.value;
    }

    fallback() external payable{
        balance += msg.value;
    }

}