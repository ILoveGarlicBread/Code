
// Machine.java
package model;

import java.util.HashSet;
import java.util.Set;

public class Machine {
    private String name;
    private Set<SparePart> spareParts = new HashSet<>();

    public Machine(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public SparePart searchSparePart(int number) {
        return spareParts.stream()
                .filter(p -> p.getNumber() == number)
                .findFirst()
                .orElse(null);
    }

    public void addSparePart(String name, int number, double price) {
        spareParts.add(new SparePart(name, number, price));
    }

    public Set<SparePart> getAllSpareParts() {
        return spareParts;
    }
}
