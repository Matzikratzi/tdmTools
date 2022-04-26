function d = pcmeval(filename)
  data = csvread(filename);

  fs = data(1, 1);
  
  figure(1);
  clf;
  figure(2);
  clf;

  accumInit = [];
  accumOkValues = [];
  
  for i = 3:66
    values = data(:, i);
    initValues = values(10:4000);
    initLen = length(initValues);
    accumInit = [accumInit initValues];

    okValues = values(40000:80000);

    accumOkValues = [accumOkValues okValues(1:60)];

    ## figure(1);
    ## subplot(8, 8, i-2);
    ## plot (initValues)

    ## V = fft(okValues);
    ## f = (0:(length(V)/2-1))/length(V)*fs;
    ## subplot(8, 8, i-2);
    ## plot(f, abs(V(1:floor(length(V)/2))));
  end

  figure(1)
  clf;
  plot(accumOkValues)
  zoom on

  figure(2)
  clf
  hold on
  zoom on
  for j = 1:4
    for i = 1:16
      plot ((i-1)*60+[1:60], accumOkValues(:, i+(j-1)*16)+(j-1)*100000, '-*')
    end
  end


  
  figure(3);
  clf;
  ## plot(f, abs(V(1:floor(length(V)/2))));
  plot(accumInit)
  zoom on
  
  figure(4);
  clf;
  hold on;
  zoom on
  for i = 1:64
    plot ((i-1)*initLen+[1:initLen], accumInit(:, i))
  end

end
	   
