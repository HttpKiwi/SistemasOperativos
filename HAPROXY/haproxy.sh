apt-get update
apt-get install -y haproxy
cd /etc/default
chmod 666 haproxy
sudo echo "ENABLED=1" >> /etc/default/haproxy
sudo rm /etc/haproxy/haproxy.cfg
cd /vagrant
sudo cp haproxy.cfg /etc/haproxy
sudo service haproxy start
sudo service haproxy restart

