# Design a Parking Lot

![image](https://hackernoon.imgix.net/hn-images/1*RF8k7w8yEaZqHgj4Bk9tKg.png)

This is one of the most common OOD interview questions and a must-know.

The interviewer will want to hear you discuss:

- **Payment Flexibility:** How are customers able to pay at different points (i.e. either at the customer’s info console on each floor or at the exit) and by different methods (cash, credit, coupon)?
- **Capacity:** How will the parking capacity of each lot be considered? What happens when a lot becomes full?
- **Vehicle Types:** How will capacity be allocated for different parking spot types — e.g. motorcycles, compact cars, electric cars, handicap vehicles, etc.?
- **Pricing:** How will pricing be handled? It should accommodate having different rates for each hour. For example, customers have to pay $4 for the first hour, $3.5 for the second and third hours, and $2.5 for all the remaining hours.

---

Walk me through the interview process for above problem


# Parking Lot Design Interview Process

When tackling the **Parking Lot Design** problem during an object-oriented design (OOD) interview, it's important to break down the problem into smaller components and discuss key aspects with your interviewer. Below is a step-by-step process that you can follow to guide the discussion:

## Step 1: Clarify Requirements

Start by asking clarifying questions to fully understand the scope of the problem. Some questions you may ask include:

- What type of parking lot is being designed? A single-level or multi-level parking lot?
- Should the design handle real-time scenarios like tracking available spots or handling payments?
- Are there specific constraints like number of floors, vehicle types, or maximum capacity?
  
This will help you define the boundaries and assumptions for your solution.

---

## Step 2: Identify Key Features

Outline the core features and requirements of a parking lot system based on the prompt:

- **Payment Flexibility**: 
    - Customers should be able to pay at different points (e.g., at an info console on each floor or at exit checkpoints).
    - Multiple payment methods should be supported (cash, credit card, coupons).
  
- **Capacity Management**: 
    - The system should track how many spots are available in real-time.
    - It should handle situations where lots become full.
  
- **Vehicle Types**:
    - The system must accommodate different types of vehicles such as motorcycles, compact cars, electric cars, and handicap vehicles.
    - Designation of specific areas for electric vehicles (with charging stations), handicap spaces close to exits/elevators.

- **Pricing Strategy**:
    - Rates may vary based on time spent in the parking lot.
    - For example: $4 for the first hour -> $3.5 for hours 2 and 3 -> $2.5 for subsequent hours.

---

## Step 3: High-Level Design (Classes & Components)

Next, propose a high-level class diagram that supports all functionalities. Start by identifying key entities and relationships between them.

### Core Classes
Here are some potential classes:

1. **ParkingLot**
   - Manages overall operations (capacity tracking, spot allocation).
   - Tracks floors and total available spots.

2. **ParkingFloor**
   - Represents each level of a multi-story parking lot.
   - Contains multiple parking spots.

3. **ParkingSpot**
   - Represents an individual space where vehicles park.
   - Can be specialized into subclasses:
     - `HandicappedSpot`
     - `CompactSpot`
     - `ElectricSpot`
     - `MotorcycleSpot`

4. **Vehicle**
   - Base class for all vehicle types.
   Could have subclasses:
     ```plaintext
     Motorcycle | Car | ElectricCar | Bus
     ```

5. **Ticket**
   Tracks entry time and calculates pricing based on exit time.

6. **PaymentSystem**
   Handles payments through different methods such as cash, credit card, or coupon.

7. **Entry/Exit Gate**
   Manages entry/exit validation through ticket scanning and payment processing integration.

---

### Example Class Diagram Mockup

```plaintext
+------------------+          +----------------------+
| ParkingLot       |<>--------| ParkingFloor          |
|------------------|          |----------------------|
| addFloor()       |<>--------| AvailableSpots        |
| removeFloor()    |<>--------| getAvailableSpots()   |
+------------------+          +----------------------+
         ^                              ^
         |                              |
         v                              v
+------------------+        +--------------------+
| ParkingSpot      |<>------| Vehicle            |
|------------------|        |--------------------|
| isAvailable()    |        | getType()          |
+------------------+        +--------------------+
         ^
         |
      Subclasses:
  HandicappedSpot / CompactSpot / ElectricSpot / MotorcycleSpot

```

For pricing logic:

1. The `Ticket` class could contain timestamps (`entryTime`, `exitTime`) to calculate fees based on time spent using predefined rates stored in a configuration file or database.
2. The `PaymentSystem` class would interact with various payment gateways depending on how customers choose to pay.

---

## Step 4: Discuss Real-Time Considerations

Once your high-level design has been explained, touch upon how you would handle real-time updates such as:

- Tracking available spots across floors in real-time via sensors or similar technology.
- Handling concurrent access—two drivers trying to park at exactly the same moment might need locking mechanisms to prevent overbooking a spot.
  
You can also bring up scaling concerns if this system were deployed across multiple locations—how would it handle hundreds or thousands of concurrent users?

---

## Step 5: Walkthrough Use Cases

Finally, walk through practical use cases with your interviewer using your diagram and explain how each component interacts within these scenarios:

### Use Case 1: Vehicle Entry
1. Driver enters through entry gate → system checks if there’s an available spot by type (e.g., compact car) → assigns spot → prints ticket with entry time/details.

### Use Case 2: Spot Allocation/Tracking Capacity
1. When a vehicle parks in its designated spot → mark that spot as "occupied" → decrement available capacity accordingly.
   
### Use Case 3: Payment Processing & Exit
1. Driver reaches exit gate → scans ticket → system calculates fee based on duration of stay → processes payment via chosen method → raises gate upon successful payment.

---

## Step 6: Optimize & Extend Features

Once you've covered core functionality, discuss potential optimizations/extensions:

- Implement dynamic pricing strategies (surge pricing during peak hours).
- Add loyalty programs where frequent customers receive discounts/coupons.
- Introduce mobile apps for remote payments or reserving spots ahead of arrival.

---

This structured approach demonstrates critical thinking about object-oriented principles while showing flexibility in handling both functional requirements and scale concerns common in designing systems like parking lots!