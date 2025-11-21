//!Create data base with name temp
CREATE DATABASE IF NOT EXISTS temp;
//!Switch to that database to perform CRUD operations
USE temp;
//!Create Table inside temp database and adding attributes/columns
CREATE TABLE student{
    id INT NOT NULL PRIMARY KEY ,//primary key
    name VARCHAR(25),
    lastname VARCHAR(25),
    salary INT,
};

INSERT INTO student 
    (id , name , lastname , salary) VALUES
    (01 , 'Himanshu','Jaglyan',38000),
    (02 , 'Rahul','Kaushik',38000),
    (03 , 'Vishal','kumar',38000),
    (04 , 'Om','Jindal',38000),
    (05 , 'Shivam','Sharma',38000);

//!Foreign Key
CREATE TABLE customer{
    Id INT PRIMARY KEY,
    Name varchar(20),
    cust_id varchar(50),
    FOREIGN KEY (cust_id) references student(id),//yani cust_id ka column foreig key hai jo student table ke primary key ko referecne ker raha hai 
};

-------------------------------------------------------------------------------------
//! JOINS
=> So there are mainly four types of joins in sql:-
i.e : 1. Inner Join.
      2. Outer Join.
        Note: Outer Join futur divided into Three parts:- 
        -> Left Join
        -> Right Join
        -> Full Join

      3. Cross Join
      4. Self Join
----------------------------------------------------------------------
//! 1) Inner Join:-
    Example: supose hamare pass two tables hai (customer) and (order) so as we know ke inner join jitni bhi matching 
             rows hai subko uthake deta hai to eske liye hum ek query likhe ke dikhate hai niche jo matching rows ko 
             join keragea or single table me convert ker dega (yani no. of rows badh jati hai as we know).

    Query:- SELECT C.* , O.* FROM customer AS C INNER JOIN order as O ON C.id = O.cutomer_id.
        Explanaiton : According to this query hamne inner join use kiya jo customer or order table me matching rows acc to
                      Primary key and Foreign key join ker dega ek hi table me and es query me dekho hamne special mention 
                      kiya hai ke customer table ko me C bolunga or Order table Ko O or condition likh de hai ON kerke.
---------------------------------------------------------------------    
//! 2) Outer Join:-
    //! i) Left Join:
    Example: Note book me maine wesa to table bana ke dikaya hai ke kesa sirf left or matching value include hoti hai 
            baki NULL ho jati hai theek hai lekin niche me query likh deta hu ke query kesa likhte hai.
    Query:- SELECT C.* , O.* FROM customer AS C LEFT JOIN order as O ON C.id = O.cutomer_id.
    //! ii) Right Join:
    Example: It is upposite to Left join bus right ka sara or left ka matching wala data.
    Query:- SELECT C.* , O.* FROM customer AS C RIGHT JOIN order as O ON C.id = O.cutomer_id.

    //! iii) FULL Join:
    Example:- Esme sabhi milega Left or right ka dono
        Note: MySql ke ander Full join keyword nahi hai ❌ esliye hum eski command dusre tarike se likhte hai 
              to esme hame command kuch ese likhte hai (Left Join 🌟Union🌟 Right Join)
    Query:- SELECT * FROM lefttable as l LEFT JOIN  righttable as r ON l.key = r.key
            UNION
            SELECT * FROM lefttable as l RIGHT JOIN righttable as r ON l.key = r.key. 
--------------------------------------------------------------------------------------

