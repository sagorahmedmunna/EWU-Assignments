package com.mycompany.unittesting;

/**
 * @author Sagor Ahmed
 * ID: 2021-3-60-117
 */
public class UnitTesting {

    public static void main(String[] args) {
        System.out.println("hello");
    }
    public int sum(int a, int b) {
        return a + b;
    }
    public int subtract(int a, int b) {
        return a - b;
    }
    public int multiply(int a, int b) {
        return a * b;
    }
    public int calculateSalary(int workingHour, boolean weekDay) {
        if (weekDay == false) return workingHour * 200;
        else if (workingHour > 48) return workingHour * 150;
        else return workingHour * 100;
    }
    public String studentStatus(String studentId, double cgpa) {
        String[] parts = studentId.split("-");
        int year = Integer.parseInt(parts[0]);
        if (year < 2024 && cgpa < 2.15) {
            return "Probation";
        } else if (year >= 2024 && cgpa < 2.4) {
            return "Probation";
        } else if (cgpa >= 3.5) {
            return "Scholarship";
        } else {
            return "Eligible";
        }
    }
}
