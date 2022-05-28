%% Example showing the affect of different clustering methods
%

%% Load some data
%
X = importdata('clusterdata.dat')

%% Plot the data
% There appear to be three clusters. As you run through this code, notice
% how the different methods give slightly different cluster. 

plot(X(:,1),X(:,2),'x')

%% Default clustering settings
%
c = clusterdata(X,3);

%% Label the clusters
% 
hold on
plot(X((c==2),1),X(c==2,2),'go')
plot(X((c==1),1),X(c==1,2),'ro')
title('Hierarchical - Single Linkage')

%% Use complete linkage
%
c = clusterdata(X,'maxclust',3,'linkage','co');
figure
plot(X(:,1),X(:,2),'x')
hold on
plot(X((c==1),1),X(c==1,2),'ro')
plot(X((c==2),1),X(c==2,2),'go')
title('Hierarchical - Complete Linkage')

%% Average linkage
%
c = clusterdata(X,'maxclust',3,'linkage','av');
figure
plot(X(:,1),X(:,2),'x')
hold on
plot(X((c==1),1),X(c==1,2),'ro')
plot(X((c==2),1),X(c==2,2),'go')
title('Hierarchical - Average Linkage')

%% K-Means clustering
%
c = kmeans(X,3,'dist','city');
figure;
plot(X(:,1),X(:,2),'x')
hold on
plot(X((c==1),1),X(c==1,2),'ro')
plot(X((c==2),1),X(c==2,2),'go')
title('Kmeans')