data1 = csvread("iterativa.csv");
data2 = csvread("recursiva.csv");

figure(1,"position",get(0,"screensize"));
plot(data1(1:end, 2), data1(1:end, 1), "b", "linewidth", 2, data2(1:end, 2), data2(1:end, 1), "r", "linewidth", 2 );

minx = min([data1(1:end, 2); data2(1:end, 2)]);
maxx = max([data1(1:end, 2); data2(1:end, 2)]);
miny = min([data1(1:end, 1); data2(1:end, 1)]);
maxy = max([data1(1:end, 1); data2(1:end, 1)]);

axis([minx-2 maxx+5 miny-2 maxy+5]);

saveas(1, "grafico.jpg")
hold on;
waitforbuttonpress();