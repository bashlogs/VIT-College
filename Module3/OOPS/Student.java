package OOPS;
class Student{
    static int cnt = 12220034;
    int PRN;
    String Name;
    String division;

    static {
        System.out.println("Static block");
    }


    {
        System.out.println("Instance block");
    }

     public Student() {
     }
    
     public Student(String name, String div) {
         this.Name = name;
         this.division = div;
         this.PRN = cnt;
         cnt++;
     }
    
     public Student(Student another) {
         this(another.Name, another.division);
     }

     static int getCurrentPRN() {
         return cnt;
     }

     String getDivision() {
         return this.division;
     }

     String getName() {
         return this.Name;
     }

     int getPRN() {
         return this.PRN;
     }

     public static void main(String args[]) {
         Student student = new Student("Mayur", "SEDA CS-C");
         System.out.println("Current PRN: " + getCurrentPRN());
         System.out.println("Student Name: " + student.getName());
         System.out.println("Student Division: " + student.getDivision());
         System.out.println("Student PRN: " + student.getPRN());
     }


}