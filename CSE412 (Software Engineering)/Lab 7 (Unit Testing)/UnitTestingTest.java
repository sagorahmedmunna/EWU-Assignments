// ID: 2021-3-60-117
// Name: Sagor Ahmed

package com.mycompany.unittesting;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * @author Sagor Ahmed
 * ID: 2021-3-60-117
 */
public class UnitTestingTest {
    
    public UnitTestingTest() {
    }

    @Test
    public void testMain() {
    }

    @Test
    public void testSum() {
        int a = 10;
        int b = 5;
        int expectedOutput = 15;
        UnitTesting test = new UnitTesting();
        int actualOutput = test.sum(a, b);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void testSubtract() {
        int a = 10;
        int b = 5;
        int expectedOutput = 5;
        UnitTesting test = new UnitTesting();
        int actualOutput = test.subtract(a, b);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void testMultiply() {
        int a = 10;
        int b = 5;
        int expectedOutput = 50;
        UnitTesting test = new UnitTesting();
        int actualOutput = test.multiply(a, b);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void testCalculateSalaryTC1() {
        int workingHour = 40;
        boolean weekDay = true;
        int expectedOutput = 4000;
        UnitTesting test = new UnitTesting();
        int actualOutput = test.calculateSalary(workingHour, weekDay);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void testCalculateSalaryTC2() {
        int workingHour = 40;
        boolean weekDay = false;
        int expectedOutput = 8000;
        UnitTesting test = new UnitTesting();
        int actualOutput = test.calculateSalary(workingHour, weekDay);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void testCalculateSalaryTC3() {
        int workingHour = 50;
        boolean weekDay = true;
        int expectedOutput = 7500;
        UnitTesting test = new UnitTesting();
        int actualOutput = test.calculateSalary(workingHour, weekDay);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void testCalculateSalaryTC4() {
        int workingHour = 50;
        boolean weekDay = false;
        int expectedOutput = 10000;
        UnitTesting test = new UnitTesting();
        int actualOutput = test.calculateSalary(workingHour, weekDay);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void teststudentStatusTC1() {
        String studentID = "2015-1-60-123";
        double cgpa = 2.00;
        String expectedOutput = "Probation";
        UnitTesting test = new UnitTesting();
        String actualOutput = test.studentStatus(studentID, cgpa);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void teststudentStatusTC2() {
        String studentID = "2025-1-60-123";
        double cgpa = 2.30;
        String expectedOutput = "Probation";
        UnitTesting test = new UnitTesting();
        String actualOutput = test.studentStatus(studentID, cgpa);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void teststudentStatusTC3() {
        String studentID = "2020-1-60-123";
        double cgpa = 2.30;
        String expectedOutput = "Eligible";
        UnitTesting test = new UnitTesting();
        String actualOutput = test.studentStatus(studentID, cgpa);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void teststudentStatusTC4() {
        String studentID = "2025-1-60-123";
        double cgpa = 2.50;
        String expectedOutput = "Eligible";
        UnitTesting test = new UnitTesting();
        String actualOutput = test.studentStatus(studentID, cgpa);
        assertEquals(expectedOutput, actualOutput);
    }
    
    @Test
    public void teststudentStatusTC5() {
        String studentID = "2022-1-60-123";
        double cgpa = 3.50;
        String expectedOutput = "Scholarship";
        UnitTesting test = new UnitTesting();
        String actualOutput = test.studentStatus(studentID, cgpa);
        assertEquals(expectedOutput, actualOutput);
    }
}
