package model;

import java.util.HashSet;
import java.util.Set;

public class Machine {

  private String name;
  private Set<Part> parts;

  public Machine(String inputName) {
    this.name = inputName;
    this.parts = new HashSet<>();

  }

  public String getName() {
    return this.name;
  }

  public Part searchPart(String partName) {
    for (Part part : parts) {
      if (part.getName().equals(partName)) {
        return part;
      }
    }
    return null;
  }

  public void addPart(String inputName, int inputNumber, int inputPrice) {
    Part part = new Part(inputName, inputNumber, inputPrice);
    parts.add(part);
  }

  public String queryPartNames() {
    StringBuilder result = new StringBuilder();
    for (Part part : this.parts) {
      result.append(part.getName());
    }
    return result.toString();
  }

  public void addPart(Part part) {
    parts.add(part);
  }

  public Set<Part> returnAllParts() {
    return parts;
  }

}
