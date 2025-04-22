public class Main {
  public static void main(String[] args) {
    Airline airline = new Airline("SkyHigh Airlines");

    airline.addPlane("Falcon", "Jet", 150);
    airline.addPlane("Eagle", "Turboprop", 80);
    airline.addPlane("Condor", "Jet", 200);

    System.out.println("Planes owned by " + airline.getName() + ":");
    for (Plane p : airline.getPlanes()) {
      System.out.println(p);
    }

    System.out.println("\nSearching for plane 'Eagle':");
    Plane found = airline.searchPlaneByName("Eagle");
    if (found != null) {
      System.out.println("Found: " + found);
    } else {
      System.out.println("Plane not found.");
    }

    int totalSeats = 0;
    for (Plane p : airline.getPlanes()) {
      totalSeats += p.getNumberOfSeats();
    }

    System.out.println("\nTotal number of seats in all planes: " + totalSeats);
  }
}
