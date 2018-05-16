
clear all;
close all;


TESTS  = 100;
SIZE   =[10000, 50000, 100000, 500000, 1000000];
SORTED =[0, 25, 50, 75, 95, 99, 99.7, -100];
TYPE   =['m', 'q', 'h', 'i'];
COL    =['g', 'r', 'b', 'm'];

for s=1:1:8
    for t=1:1:4
        for sz=1:1:5
            results(s,t,sz) = mean(importdata(strcat('tests.tmp/',TYPE(t),'_sort_',num2str(SORTED(s)),'_sorted_',num2str(SIZE(sz)),'_size_',num2str(TESTS),'.txt')));
        end
    end
end


for s=1:1:8
    figure(s);
    title(strcat('Sorted:',num2str(SORTED(s))))
    hold on
    grid on;
    grid minor;
    ylabel('Time [ms]');
    xlabel('Size [n]');
    set(gca, 'XScale', 'log')
    set(gca, 'YScale', 'log')

    for t=1:1:4
        p = plot(SIZE,squeeze(results(s,t,:)),COL(t));
        p.MarkerSize = 10;
        p.Marker = '.';
    end
    lgd = legend('Mergesort','Quicksort','Heapsort','Introsort');
    lgd.Location = 'southeast';
end