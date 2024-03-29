package OOPS;
class Participants{
    static int counter = 1001;
    String registrationId;
    String name;
    long contactNumber;
    String branch;

    public int getCounter() {
        return counter;
    }

    public String getRegistrationId() {
        return registrationId;
    }

    public void setRegistrationId(String registrationId) {
        this.registrationId = registrationId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getContactNumber() {
        return contactNumber;
    }

    public void setContactNumber(long contactNumber) {
        this.contactNumber = contactNumber;
    }

    public String getBranch() {
        return branch;
    }

    public void setBranch(String branch) {
        this.branch = branch;
    }

    public Participants(String name, long contact, String branch){
        this.name = name;
        this.contactNumber = contact; 
        this.branch = branch;
        this.registrationId = "D" + counter;
        counter++;
    }

    public static void main(String args[]){
        Participants participant1 = new Participants("Rohit",1234567889l, "Computer");
        System.out.println("Hi " + participant1.getName() + "! Your registration id is " + participant1.getRegistrationId());
    
        Participants participant2 = new Participants("Sayli",1988612300l, "Mechanical");
        System.out.println("Hi " + participant2.getName() + "! Your registration id is " + participant2.getRegistrationId());
    
    }
}