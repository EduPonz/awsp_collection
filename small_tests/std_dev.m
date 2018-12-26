A = [3148,3366,3371,2911,3362,3358,3359,3354,3359,3352];

Std = std(A)
Mean = mean2(A)


z_score = 2.576;
format longG;

conf_interval = Mean - (z_score * (Std / sqrt(10)))
conf_interval2 = Mean + (z_score * (Std / sqrt(10)))