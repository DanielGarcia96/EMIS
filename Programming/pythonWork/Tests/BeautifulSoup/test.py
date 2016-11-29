from BeautifulSoup import BeautifulSoup
import requests

r = requests.get("http://www.pythonforbeginners.com/python-on-the-web/web-scraping-with-beautifulsoup/");
data = r.text
soup = BeautifulSoup(data)

p = soup.body.findAll("a");
for l in p:
   print(l)
