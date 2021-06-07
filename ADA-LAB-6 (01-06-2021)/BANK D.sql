CREATE DATABASE banking_enterprise_db;
USE banking_enterprise_db; 

CREATE TABLE Branch(
	branch_name VARCHAR(20),
	branch_city VARCHAR(10),
	assets REAL,
    PRIMARY KEY(branch_name)
    );

CREATE TABLE Accounts(
	accno integer,
    branch_name VARCHAR(20),
    balance REAL,
    PRIMARY KEY(accno),
    FOREIGN KEY(branch_name) REFERENCES Branch(branch_name)
    );

CREATE TABLE Depositor(
	customername VARCHAR(20),
	customerstreet VARCHAR(30),
    customercity VARCHAR(30),
    PRIMARY KEY(customername)
    );
    
CREATE TABLE Loan(
	loanno int,
    branch_name VARCHAR(20),
    amt REAL,
    PRIMARY KEY(loanno),
    FOREIGN KEY(branch_name) REFERENCES Branch(branch_name)
    );


CREATE TABLE Borrower(
	customername varchar(20),
	loanno int,
    FOREIGN KEY(customername) REFERENCES Depositor(customername),
    FOREIGN KEY(loanno) REFERENCES Loan(loanno)
    );

INSERT INTO Branch VALUES('SBI_Chamrajpet','Bangalore',50000);
INSERT INTO Branch VALUES('SBI_Residency road','Bangalore',10000);
INSERT INTO Branch VALUES('SBI_shivajiroad','Bombay',20000);
INSERT INTO Branch VALUES('SBI_parlimentroad','Delhi',10000);
INSERT INTO Branch VALUES('SBI_jantarmantar','Delhi',20000);
SELECT * FROM Branch;

INSERT INTO Accounts VALUES('1','SBI_Chamrajpet','2000');
INSERT INTO Accounts VALUES('2','SBI_Residency road','5000');
INSERT INTO Accounts VALUES('3','SBI_shivajiroad','6000');
INSERT INTO Accounts VALUES('4','SBI_parlimentroad','9000');
INSERT INTO Accounts VALUES('5','SBI_jantarmantar','8000');
SELECT * FROM Accounts;

INSERT INTO Depositor VALUES('AVINASH','Bulltemple','Bangalore');
INSERT INTO Depositor VALUES('dinesh','banerghata','Bangalore');
INSERT INTO Depositor VALUES('mohan','mgroad','Bangalore');
INSERT INTO Depositor VALUES('nikhil','churchstreeet','Delhi');
INSERT INTO Depositor VALUES('ravi','akbarroad','Delhi');
SELECT * FROM Depositor;

INSERT INTO Loan VALUES(1,'SBI_Chamrajpet',1000);
INSERT INTO Loan VALUES(2,'SBI_Residency road',2000);
INSERT INTO Loan VALUES(3,'SBI_shivajiroad',3000);
INSERT INTO Loan VALUES(4,'SBI_parlimentroad',4000);
INSERT INTO Loan VALUES(5,'SBI_jantarmantar',5000);
SELECT * FROM Loan;