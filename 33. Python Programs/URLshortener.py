from pyshorteners import Shortener
api_key="56ad10bf8f66e5da5d5cde4fca0194d7be16db8d"
shortener=Shortener(api_key= api_key)
long_url="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.pinterest.com%2Fprior1390%2Fpokemon-images%2F&psig=AOvVaw2_xjfKW_Nvh5Ujxmqf9kR0&ust=1632317830366000&source=images&cd=vfe&ved=0CAsQjRxqFwoTCIjVm_WXkPMCFQAAAAAdAAAAABAD"
short_url=shortener.bitly.short(long_url)
print(short_url)
#long_url=shortener.bitly.expand(short_url)