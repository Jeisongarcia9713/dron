 
Data=simout.Data;
for datos=155:162;
    %datos=220:260
    %datos=220:250
    close all  
    img=Data(:,:,datos);
    imshow(Data(:,:,datos));
    hold on 
    j=1;
    i=1;
    table=zeros(120,3);
    %se calcula el centro de cada fila y el valor de pixeles por fila en 1 
    cuenta=0;
    for i=1:120
        suma=0;pos_j=0;
        %suma cuenta el valor de pixeles por fila
        %pos_j sumatoria de posicion en la columna donde los pixeles tienen valor 1
        for j=1:160
            if img(i,j)
                pos_j=pos_j+j;
                suma=suma+1;
            end
        end
        if(suma)
        cuenta=cuenta+1;
        table(cuenta,1)=pos_j/suma;
        table(cuenta,2)=suma;
        table(cuenta,3)=i;
        end
        %promedio para encontrar centro
         % sumatoria de pixeles 
    end
    % se determinan el centro principal y el centro auxiliar de la imagen
    centro1=0;centro2=0;
    suma1=0; suma2=0;
    for i=1:120
        if (table(i,2)<30) && (table(i,2)>15)
            centro1=centro1+table(i,1);
            suma1=suma1+1;
        elseif(table(i,2))>40
            centro2=centro2+table(i,1);
            suma2=suma2+1;
        end   
    end
    if(suma1>0)
        centro_p=centro1/suma1;
        plot(centro_p,1:120,'*r')
    else
        centro_p=0;
    end
    if(suma2>0)
        centro_a=centro2/suma2;
        plot(centro_a,1:120,'*g')
    else
        centro_a=0;
    end
    i=1;
    % funcion filtro
    inicio=0;
    fin=0;
    while i<111
        if(table(i,2)>15)
            if (inicio==0)
                if abs(table(i,1)-table(i+6,1))>=1
                    inicio=table(i,3);
               elseif i<90 && abs(tabla(i,1)-tabla(i+30,1))>=15 && abs(tabla(i,1)-tabla(i+1,1))<=1 && abs(tabla(i,1)-tabla(i+2,1))<=1
                    inicio=i;
                else
                    i=111;     
                end
            elseif abs(table(i,1)-table(i+10,1))<=1
                fin=table(i,3);
                i=111;
            end
        end
        i=i+1;
    end
    j=inicio:fin;
    linea=zeros(100,2);
    % funcion filtro 1
    cuentas=1;
    if(inicio && fin)
          valido=1;
        if(centro_a>0)
            cuenta=1;
            if(centro_a>centro_p)
                ini=floor(centro_p+12);
                fi=160;
            else
                ini=1;
                fi=floor(centro_p-12);
            end
            for j=ini:fi
                suma=0;pos_i=0;
                for i=1:120
                   if(img(i,j))
                      pos_i=pos_i+i;
                      suma=suma+1;
                   end
                end
                if(suma)
                    linea(cuenta,1)=pos_i/suma;
                    linea(cuenta,2)=j;
                    cuentas=cuenta;
                    cuenta=cuenta+1;
                    
                    plot(linea(:,2),linea(:,1),'b*')
                    title('cuadra_a>0')
                end
            end
        else
            linea(1:fin-inicio+1,1)=table(j,3) ;
            linea(1:fin-inicio+1,2)=table(j,1) ;
            cuentas=fin-inicio+1;
            plot(linea(:,2),linea(:,1),'b*')
            title('cuadro_a==0')
        end
    else
        title('no valido')
        valido=0;
    end
    
    linea=linea(1:cuentas,:);
    pendiente=0;
    cuadrante=0;
    i=length(linea); 
    if(i>2 && valido)
        f=polyfit(linea(1:i,2),120-linea(1:i,1),1);
        pendiente=f(1);
        if (abs(pendiente)>80)
            if(max(linea(:,2)))>100
                cuadrante=5;
            elseif(min(linea(:,2)))<60
                cuadrante=6;
            end     
        elseif(pendiente>0 )
            if (abs(min(linea(:,2))-centro_p)>abs(max(linea(:,2))-centro_p) ) 
                cuadrante=3;
            else
                cuadrante=1;
            end
        elseif(pendiente<0)
            if (abs(min(linea(:,2))-centro_p)>abs(max(linea(:,2))-centro_p) )
                cuadrante=4;
            else
                cuadrante=2;
            end
        end  
    end    
    title(strcat('cuadrante :',num2str(cuadrante),' valido: ', num2str(valido)));
    pause(2);
end