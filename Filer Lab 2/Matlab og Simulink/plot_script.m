% logg over plot

% test 1 til og med 5
% Eksperimenterte med forskjellige polplasseringer med K = place()
% plottet sprangresponsen på elevation.
% 
% Test 6 til og med 10
% Brukte LQR uten integralvirkning og testet ut respons på elevation
% Test 9 var pitch, 10 var pitch og elevation

% Test 11 til og med 15
% LQR med integralvirkning
% 
% Test 16 endelig Q og R med step og kjøretest

hold on
 
 
%  plot(eigs4_respons(1, :), eigs4_respons(7, :))
%  plot(Q1R1_respons(1, :), Q1R1_respons(7, :))

% beste LQR på elevation
%  plot(Q1R3_respons(1, :), Q1R3_respons(7, :))
% plot(Q1intR3_respons(1, :), Q1intR3_respons(7, :))
%  plot(Q2intR3_respons(1, :), Q2intR3_respons(7, :))
%  plot(Q3intR3_respons(1, :), Q3intR3_respons(7, :))
 %plot(Q4intR3_respons(1, :), Q4intR3_respons(9, :))
 plot(endeligQintR3_respons(1, :), endeligQintR3_respons(7, :))
 plot(endeligQintR3_respons(1, :), endeligQintR3_respons(8, :))
 %legend('ref','Q4','Q5')
 grid on
 %xlim([0 8])
 figure
 hold on
  plot(endeligQintR3_respons(1, :), endeligQintR3_respons(4, :))
 plot(endeligQintR3_respons(1, :), endeligQintR3_respons(9, :))