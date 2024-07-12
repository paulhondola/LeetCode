int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration) {
  // [1, 4] , 2, duration = 2

  int timePoisoned = 0;

  if (timeSeriesSize == 0)
    return 0;

  timePoisoned += duration;

  for (int i = 1; i < timeSeriesSize; i++) {
    if (timeSeries[i] - timeSeries[i - 1] >= duration) {
      timePoisoned += duration;
    } else {
      timePoisoned += timeSeries[i] - timeSeries[i - 1];
    }
  }

  return timePoisoned;
}
