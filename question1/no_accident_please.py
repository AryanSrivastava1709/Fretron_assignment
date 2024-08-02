import matplotlib.pyplot as plt
from typing import List, Tuple

def ccw(A: Tuple[float, float], B: Tuple[float, float], C: Tuple[float, float]) -> bool:
    return (C[1]-A[1]) * (B[0]-A[0]) > (B[1]-A[1]) * (C[0]-A[0])

def intersect(A: Tuple[float, float], B: Tuple[float, float], C: Tuple[float, float], D: Tuple[float, float]) -> bool:
    return ccw(A,C,D) != ccw(B,C,D) and ccw(A,B,C) != ccw(A,B,D)

def adjust_path(path: List[Tuple[float, float]], other_paths: List[List[Tuple[float, float]]]) -> List[Tuple[float, float]]:
    adjusted_path = path.copy()
    for i in range(1, len(path)):
        for other_path in other_paths:
            for j in range(1, len(other_path)):
                if intersect(path[i-1], path[i], other_path[j-1], other_path[j]):
                    # Adjust the current point slightly
                    adjusted_path[i] = (path[i][0] + 0.1, path[i][1] + 0.1)
    return adjusted_path

def plot_flight_paths(flights: List[List[Tuple[float, float]]]):
    plt.figure(figsize=(10, 10))
    colors = ['b', 'r', 'g', 'c', 'm', 'y', 'k']
    
    adjusted_paths = []
    for i, flight in enumerate(flights):
        adjusted_path = adjust_path(flight, adjusted_paths)
        adjusted_paths.append(adjusted_path)
        
        x, y = zip(*adjusted_path)
        plt.plot(x, y, f'{colors[i % len(colors)]}-o', label=f'Flight {i+1}')
        
    plt.title("Flight Paths")
    plt.xlabel("X coordinate")
    plt.ylabel("Y coordinate")
    plt.legend()
    plt.grid(True)
    plt.show()

# Function to get user input
def get_user_input() -> List[List[Tuple[float, float]]]:
    flights = []
    num_flights = int(input("Enter the number of flights: "))
    
    for i in range(num_flights):
        flight = []
        print(f"Enter coordinates for flight {i+1} (enter 'done' when finished):")
        while True:
            coord = input("Enter coordinate (x,y): ")
            if coord.lower() == 'done':
                break
            x, y = map(float, coord.split(','))
            flight.append((x, y))
        flights.append(flight)
    
    return flights

# Get user input
flights = get_user_input()

# Plot the flight paths
plot_flight_paths(flights)
