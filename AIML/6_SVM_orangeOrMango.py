
import numpy as np
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score

# Define features (weight in grams, diameter in cm) and labels (0 for orange, 1 for mango)
X = np.array([[100, 5], [150, 6], [130, 5.5], [200, 7], [230, 8], [250, 9]])
y = np.array([0, 0, 0, 1, 1, 1])  # 0 for orange, 1 for mango

# Initialize the SVM classifier
clf = SVC(kernel='linear')

# Train the classifier
clf.fit(X, y)

# Test the classifier with some examples
test_data = np.array([[120, 5.5], [220, 7.5]])
true_labels = np.array([0, 1])  # Expected labels: 0 for orange, 1 for mango

# Predict the labels
predicted_labels = clf.predict(test_data)

# Calculate accuracy
accuracy = accuracy_score(true_labels, predicted_labels)
print("Accuracy:", accuracy)

# Print the predicted labels
for i, label in enumerate(predicted_labels):
    fruit = "orange" if label == 0 else "mango"
    print(f"Predicted label for test data {test_data[i]}: {fruit}")
