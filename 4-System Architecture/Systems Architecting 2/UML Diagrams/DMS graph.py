# import networkx as nx
# import matplotlib.pyplot as plt

# # Create a new graph
# G = nx.DiGraph()

# # Add nodes for actors and use cases
# G.add_node("Driver", shape="ellipse")
# G.add_node("Driver Monitoring System", shape="box")
# G.add_node("Surrounding Vehicles", shape="ellipse")

# # Add edges to represent interactions
# G.add_edge("Driver", "Driver Monitoring System", label="Interact")
# G.add_edge("Driver Monitoring System", "Surrounding Vehicles", label="Alert")
# G.add_edge("Surrounding Vehicles", "Driver Monitoring System", label="Respond")

# # Define additional use cases
# use_cases = {
#     "Detect Drowsiness": "Monitors driver's eye movements and behavior for signs of drowsiness.",
#     "Detect Distraction": "Monitors driver's activities for signs of distraction, such as smartphone use.",
#     "Generate Alerts": "Generates alerts for the driver in case of drowsiness or distraction.",
#     "Communicate with Central System": "Transmits driver behavior data to a central monitoring system.",
#     "Receive Central Alerts": "Receives alerts and updates from the central monitoring system.",
#     "Initiate Emergency Braking": "Initiates emergency braking if severe driver distraction is detected.",
# }

# # Add use case nodes and descriptions
# for use_case, description in use_cases.items():
#     G.add_node(use_case, shape="box", label=use_case + "\n" + description)

# # Connect use cases to the Driver Monitoring System
# for use_case in use_cases:
#     G.add_edge("Driver Monitoring System", use_case)

# # Define node positions (optional)
# pos = {
#     "Driver": (0, 2),
#     "Driver Monitoring System": (1, 1),
#     "Surrounding Vehicles": (2, 2),
#     "Detect Drowsiness": (3, 3),
#     "Detect Distraction": (3, 1.5),
#     "Generate Alerts": (3, -1.5),
#     "Communicate with Central System": (3, -3),
#     "Receive Central Alerts": (4, -1),
#     "Initiate Emergency Braking": (5, -0.5),
# }

# # Draw the graph
# options = {
#     "node_color": "lightblue",
#     "node_size": 1500,
#     "with_labels": True,
#     "font_size": 8,
#     "font_color": "black",
#     "arrowsize": 20,
# }

# nx.draw(G, pos, **options)

# # Add edge labels
# edge_labels = nx.get_edge_attributes(G, "label")
# nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=6)

# # Display the graph
# plt.axis("off")
# plt.show()

import matplotlib.pyplot as plt

# Define the activities and decisions
activities = [
    "Start",
    "Driver Interaction",
    "Detect Drowsiness",
    "Detect Distraction",
    "Generate Alerts",
    "Communicate with Central System",
    "Receive Central Alerts",
    "Initiate Emergency Braking",
    "End",
]

decisions = [
    "Drowsiness Detected?",
    "Distraction Detected?",
    "Emergency Braking?",
]

# Create the activity diagram
plt.figure(figsize=(10, 6))
ax = plt.gca()

# Set the horizontal spacing between activities and decisions
horizontal_spacing = 1.5

# Create nodes for activities
for i, activity in enumerate(activities):
    ax.annotate(activity, xy=(i * horizontal_spacing, 0.5), fontsize=12, ha="center", va="center",
                bbox=dict(boxstyle="round,pad=0.3", edgecolor="black"))

# Create nodes for decisions
for i, decision in enumerate(decisions):
    ax.annotate(decision, xy=(i * horizontal_spacing + horizontal_spacing / 2, 2), fontsize=12, ha="center", va="center",
                bbox=dict(boxstyle="round,pad=0.3", edgecolor="black"))

# Draw arrows to represent control flow
for i in range(len(activities) - 1):
    ax.annotate("", xy=(i * horizontal_spacing + horizontal_spacing, 0.45),
                xytext=(i * horizontal_spacing + horizontal_spacing, 1.55), arrowprops=dict(arrowstyle="->"))

# Draw arrows to represent decision branches
ax.annotate("", xy=(2 * horizontal_spacing, 1.45), xytext=(3 * horizontal_spacing, 2.55), arrowprops=dict(arrowstyle="->"))
ax.annotate("", xy=(3 * horizontal_spacing, 1.45), xytext=(4 * horizontal_spacing, 2.55), arrowprops=dict(arrowstyle="->"))
ax.annotate("", xy=(4 * horizontal_spacing, 1.45), xytext=(5 * horizontal_spacing, 2.55), arrowprops=dict(arrowstyle="->"))

# Draw arrows to connect decisions to activities
ax.annotate("", xy=(2 * horizontal_spacing, 1.45), xytext=(2 * horizontal_spacing, 0.55), arrowprops=dict(arrowstyle="->"))
ax.annotate("", xy=(3 * horizontal_spacing, 2.45), xytext=(3 * horizontal_spacing, 1.55), arrowprops=dict(arrowstyle="->"))
ax.annotate("", xy=(4 * horizontal_spacing, 2.45), xytext=(4 * horizontal_spacing, 1.55), arrowprops=dict(arrowstyle="->"))

# Set axis properties
ax.set_xlim(0, (len(activities) - 1) * horizontal_spacing)
ax.set_ylim(0, 3)
ax.axis("off")

# Add a title
plt.title("Driver Monitoring System Activity Diagram", fontsize=14)

# Show the diagram
plt.show()
