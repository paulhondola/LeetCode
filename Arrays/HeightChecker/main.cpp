int heightChecker(vector<int> &heights) {
  vector<int> sorted_vector = heights;

  sort(sorted_vector.begin(), sorted_vector.end());

  int count = 0;

  for (int i = 0; i < heights.size(); i++)
    if (heights[i] != sorted_vector[i])
      count++;
  return count;
}
