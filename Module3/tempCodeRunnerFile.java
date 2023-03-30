

public class Melange {
private String name;
    private String branch;
    private String registrationId;
    private long ContactNumber;
    private static int counter;
    
    static
    {
        counter=1001;
    }
    
    public Melange(String name, long ContactNumber, String branch)
    {
        this.name=name;
        this.branch= branch;
        this.ContactNumber=ContactNumber;
        this.registrationId="D"+ counter;
        Melange.counter++;
    }

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getBranch() {
		return branch; 
	}

	public void setBranch(String branch) {
		this.branch = branch;
	}

	public long getContactNumber() {
		return ContactNumber;
	}

	public void setContactNumber(long contactNumber) {
		ContactNumber = contactNumber;
	}

	public static int getCounter() {
		return counter;
	}

	public static void setCounter(int counter) {
		Melange.counter = counter;
	}

	public String getRegistrationId() {
		return registrationId;
	}
	
	public static void main(String[] args)
    {
		Melange student1 = new Melange("Mayur", 900583874, "Computer" );
		Melange student2 = new Melange("Yash", 849593774, "Mechanical");

        System.out.println("Hi " +student1.getName()+"! Your registration id is "+ student1.getRegistrationId());
        
        System.out.println("Hi " +student2.getName()+"! Your registration id is "+ student2.getRegistrationId());
        
    }
}
