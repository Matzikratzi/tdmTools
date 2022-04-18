function d = pcmeval(filename)
  data = csvread(filename);

  fs = data(1, 1);
  
  figure(1);
  clf;
  figure(2);
  clf;
  
  for i = 3:66
    values = data(:, i);
    initValues = values(10:4000);
    okValues = values(40000:80000);

    figure(1);
    subplot(8, 8, i-2);
    plot (initValues)

    V = fft(okValues);
    f = (0:(length(V)/2-1))/length(V)*fs;
    figure(2);
    subplot(8, 8, i-2);
    plot(f, abs(V(1:floor(length(V)/2))));
  end

  figure(3);
  
  plot(f, abs(V(1:floor(length(V)/2))));
    
end
	   
