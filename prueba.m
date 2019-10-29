datos=90;
Data=simout.Data;

for i=130:length(Data)
    subplot(1,2,1)
    imshow(Data(:,:,i))
    [ancho,vert,rangos,p_vert]=vertical(Data(:,:,i));
    [linea,cuadrante,pendiente]=cuadrantes(rangos,ancho,vert);
    gra=Egrados(linea,cuadrante,pendiente,p_vert);
    subplot(1,2,2)
    plot(linea(:,2),120-linea(:,1),'r.');
    hold off
    axis([0 160 0 120])
    title(strcat('linea 1 :',num2str(gra),' cuadrante :', num2str(cuadrante)...
        ,' ancho :', num2str(ancho), ' p_vert :', num2str(p_vert)...
        ,' pendiente :', num2str(pendiente)))
   pause(1);
end
function[ancho, vert, rangos,p_vert]=vertical(imagen)
    c=size(imagen);
    table=zeros(2*c(1),2);
    i=1;
    cuenta=0;   
    for j=1:c(2)
        while i<=c(1)
            if imagen(i,j)
                    cuenta=cuenta+1;
                    table(cuenta,:)=[i j];
                    i=c(1)+1;
            end
            i=i+1;
        end
        i=1;
    end
    vert=table(1:cuenta,:);
    j=1;suma=0;rangos=zeros(4,1);cuenta=0; 
    while j<=(length(vert)-1)
        if vert(j,1)==vert(j+1,1)
            suma=suma+1;
        else
            if(suma>10)
               cuenta=cuenta+1;
               rangos(2*cuenta-1)=j-(suma);
               rangos(2*cuenta)=j;
            end     
            suma=0;
        end
        j=j+1;
    end
    if (~rangos) 
         if suma>10
             rangos=[(j-(suma));(j-(suma));length(vert);length(vert)]; 
             p_vert=min(vert(rangos,1));
             rangos=rangos(vert(rangos,1)==p_vert);
             ancho=-vert(rangos(1),2)+vert(rangos(length(rangos)),2);
         else
         rangos=[length(vert);length(vert);length(vert);length(vert)];
         ancho=0;
         p_vert=min(vert(:,1));
         end           
    else
    if(cuenta==1)
        if(suma)
             rangos=[rangos(1:2);(j-(suma));length(vert);]
        else
             rangos=[rangos(1);rangos(1);rangos(2);rangos(2);];
        end
    end
    p_vert=min(vert(rangos,1));
    rangos=rangos(vert(rangos,1)==p_vert);
    ancho=-vert(rangos(1),2)+vert(rangos(length(rangos)),2);
    end
end
function [linea,cuadrante,pendiente]=cuadrantes(rangos,ancho,vert)
     pendiente=0;
     cuadrante=0;
     linea1=0;linea2=[];
     if(rangos)
        linea1=vert(1:rangos(1),:);
        if(length(linea1)>2)
            d_linea1=abs(diff(linea1(:,1)));
            if(d_linea1(length(d_linea1))> (mean(d_linea1(1:length(d_linea1)-1))+9))
                linea1=vert(rangos(1),:);
            end
        end
        linea2=vert(rangos(length(rangos)):length(vert),:);
        if(length(linea2)>2)
            d_linea2=abs(diff(linea2(:,1)));
            if( d_linea2(1) > (mean(d_linea2(2:length(d_linea2)))+9))
                linea2=vert(rangos(length(rangos)),:);
            end
        end
    else
        linea1=vert;  
    end
    
    if(~isempty(linea2))
        if(length(linea1)>length(linea2))
            linea=linea1;
        else
            linea=linea2;
        end
    else
        linea=linea1;
    end
    i=length(linea); 
    if(length(linea)>3)
        while(linea(i,2)>148 && linea(i,1)<20)
           i=i-1; 
        end
    end
    
    if (length(linea)>2)
        f=polyfit(linea(1:i,2),120-linea(1:i,1),1);
        pendiente=f(1);
        if(pendiente>0)
            if abs(min(linea(:,2)+12)-80)>abs(max(linea(:,2)+12)-80)
                cuadrante=3;
            else
                cuadrante=1;
            end
        else
            if abs(min(linea(:,2)-12)-80)>abs(max(linea(:,2)-12)-80)
                cuadrante=4;
            else
                cuadrante=2;
            end
        end
    else
        if(ancho>30)
            if(max(vert(:,2)))>100
                cuadrante=5;
            elseif(min(vert(:,2)))<60
                cuadrante=6;
            end
        else    
            cuadrante=0;
        end
    end    
end
function grad=Egrados(linea,cuadrante,pendiente,p_vert)
    grad=0;
    switch(cuadrante)
        case 1
            if(max(linea(:,1))>48)
                grad=90-atand(pendiente);
            end
        case 2
            if(p_vert>48)
                grad=(180-(90-atand(abs(pendiente))));
            end
        case 3
            if(p_vert>48)
                grad=-(180-(90-atand(abs(pendiente))));
            end
        case 4
            if(max(linea(:,1))>48)
                grad=-(90-atand(abs(pendiente)));
            end
        case 5
            if(p_vert>48)
                grad=90;
            end
        case 6  
            if(p_vert>48)
                grad=-90;
            end
        otherwise
            grad=0;
    end
end
function y=horizontal(imagen)
    c=size(imagen);
    table=zeros(c(1),3);
    cambio=1;
    cuenta=0;
    for i=1:c(1)
        S1=0;
        j=1;
        while j<=c(2)
            if imagen(i,j)==1
                cuenta=cuenta+1;
            end
            if imagen(i,j)==cambio
                S1=S1+1;
                if cambio && S1==1
                        S1=1;
                        table(i,1)=j;
                        cambio=0;
                else
                    cambio=1;
                    if S1==4
                        table(i,2)=j;
                        j=c(2)+1;
                    end
                end
            end
            j=j+1;
        end
        cambio=1;
        table(i,3)=cuenta;
        cuenta=0;
    end
    y=table;
end
function y=horizontal1(imagen)
    c=size(imagen);
    table=zeros(c(1),2);
    cambio=1;
    for i=1:c(1)
        S1=0;
        j=120;
        while j>=1
            if imagen(i,j)==cambio
                S1=S1+1;
                if cambio && S1==1
                        S1=1;
                        table(i,1)=j;
                        cambio=0;
                else
                    cambio=1;
                    if S1==4
                        table(i,2)=j;
                        j=0;
                    end
                end
            end
            j=j-1;
        end
        cambio=1;
    end
    y=table;
end

% function[ancho, vert, rangos,p_vert]=vertical(imagen)
%     c=size(imagen);
%     table=zeros(c(1),2);
%     i=1;
%     cuenta=0;
%     for j=1:c(2)
%         while i<=c(1)
%             if imagen(i,j)
%                     cuenta=cuenta+1;
%                     table(cuenta,:)=[i j];
%                     i=c(1)+1;
%             end
%             i=i+1;
%         end
%         i=1;
%     end
%     vert=table(1:cuenta,:);
%     j=1;suma=0;rangos=zeros(4,1);cuenta=0; 
%     while j<=(length(vert)-1)
%         if vert(j,1)==vert(j+1,1)
%             suma=suma+1;
%         else
%             if(suma>10)
%                cuenta=cuenta+1;
%                rangos(2*cuenta-1)=j-(suma);
%                rangos(2*cuenta)=j;
%             end     
%             suma=0;
%         end
%         j=j+1;
%     end
%     if (~rangos) 
%          if suma>10
%              rangos(rangos==0)=[];
%              rangos=[rangos;(j-(suma));length(vert)];
%              p_vert=min(vert(rangos,1));
%              rangos=rangos(vert(rangos,1)==p_vert);
%              ancho=-vert(rangos(1),2)+vert(rangos(length(rangos)),2);
%          else
%          rangos=[length(vert);length(vert)];
%          ancho=0;
%          p_vert=min(vert(:,1));
%          end           
%     else
%     rangos(rangos==0)=[];
%     p_vert=min(vert(rangos,1));
%     rangos=rangos(vert(rangos,1)==p_vert);
%     ancho=-vert(rangos(1),2)+vert(rangos(length(rangos)),2);
%     end
%    
% end
% function [linea,cuadrante,pendiente]=cuadrantes(rangos,ancho,vert)
%      pendiente=0;
%      linea1=0;linea2=[];
%      if(rangos)
%         linea1=vert(1:rangos(1),:);
%         if(length(linea1)>2)
%             d_linea1=abs(diff(linea1(:,1)));
%             if(d_linea1(length(d_linea1))> (mean(d_linea1(1:length(d_linea1)-1))+9))
%                 linea1=vert(rangos(1),:);
%             end
%         end
%         linea2=vert(rangos(length(rangos)):length(vert),:);
%         if(length(linea2)>2)
%             d_linea2=abs(diff(linea2(:,1)));
%             if( d_linea2(1) > (mean(d_linea2(2:length(d_linea2)))+9))
%                 linea2=vert(rangos(length(rangos)),:);
%             end
%         end
%     else
%         linea1=vert;  
%     end
%     
%     if(~isempty(linea2))
%         if(length(linea1)>length(linea2))
%             linea=linea1;
%         else
%             linea=linea2;
%         end
%     else
%         linea=linea1;
%     end
%     
%     if (length(linea)>2)
%         f=polyfit(linea(:,2),120-linea(:,1),1);
%         pendiente=f(1);
%         if(pendiente>0)
%             if abs(min(linea(:,2)+12)-80)>abs(max(linea(:,2)+12)-80)
%                 cuadrante=3;
%             else
%                 cuadrante=1;
%             end
%         else
%             if abs(min(linea(:,2)-12)-80)>abs(max(linea(:,2)-12)-80)
%                 cuadrante=4;
%             else
%                 cuadrante=2;
%             end
%         end
%     else
%         if(ancho>30)
%             if(max(vert(:,2)))>100
%                 cuadrante=5;
%             elseif(min(vert(:,2)))<60
%                 cuadrante=6;
%             end
%         else    
%             cuadrante=0;
%         end
%     end    
% end
% function grad=grados(linea,cuadrante,pendiente,p_vert)
%     grad=0;
%     switch(cuadrante)
%         case 1
%             if(max(linea(:,1))>48)
%                 grad=90-atand(pendiente);
%             end
%         case 2
%             if(p_vert>48)
%                 grad=(180-(90-atand(abs(pendiente))));
%             end
%         case 3
%             if(p_vert>48)
%                 grad=-(180-(90-atand(abs(pendiente))));
%             end
%         case 4
%             if(max(linea(:,1))>48)
%                 grad=-(90-atand(abs(pendiente)));
%             end
%         case 5
%             if(p_vert>48)
%                 grad=90;
%             end
%         case 6  
%             if(p_vert>48)
%                 grad=-90;
%             end
%         otherwise
%             grad=0;
%     end
% end
% function y=horizontal(imagen)
%     c=size(imagen);
%     table=zeros(c(1),3);
%     cambio=1;
%     cuenta=0;
%     for i=1:c(1)
%         S1=0;
%         j=1;
%         while j<=c(2)
%             if imagen(i,j)==1
%                 cuenta=cuenta+1;
%             end
%             if imagen(i,j)==cambio
%                 S1=S1+1;
%                 if cambio && S1==1
%                         S1=1;
%                         table(i,1)=j;
%                         cambio=0;
%                 else
%                     cambio=1;
%                     if S1==4
%                         table(i,2)=j;
%                         j=c(2)+1;
%                     end
%                 end
%             end
%             j=j+1;
%         end
%         cambio=1;
%         table(i,3)=cuenta;
%         cuenta=0;
%     end
%     y=table;
% end
% function y=horizontal1(imagen)
%     c=size(imagen);
%     table=zeros(c(1),2);
%     cambio=1;
%     for i=1:c(1)
%         S1=0;
%         j=120;
%         while j>=1
%             if imagen(i,j)==cambio
%                 S1=S1+1;
%                 if cambio && S1==1
%                         S1=1;
%                         table(i,1)=j;
%                         cambio=0;
%                 else
%                     cambio=1;
%                     if S1==4
%                         table(i,2)=j;
%                         j=0;
%                     end
%                 end
%             end
%             j=j-1;
%         end
%         cambio=1;
%     end
%     y=table;
% end

