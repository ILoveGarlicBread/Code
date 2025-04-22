import java.util.HashSet;
import java.util.Set;

public class Airline {
  private String name;
  private Set<Plane> planes;

  public Airline(String name) {
    this.name = name;
    this.planes = new HashSet<>();
  }

  public Plane searchPlaneByName(String planeName) {
    for (Plane plane : planes) {
      if (plane.getName().equals(planeName)) {
        return plane;
      }
    }
    return null;
  }

  public void addPlane(String name, String type, int numberOfSeats) {
    Plane plane = new Plane(name, type, numberOfSeats);
    planes.add(plane);
  }

  public Set<Plane> getPlanes() {
    return planes;
  }

  public String getName() {
    return name;
  }
}
