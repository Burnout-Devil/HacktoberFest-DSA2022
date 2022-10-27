def PascalTriangle(n):
   trow = [1]
   y = [0]
   
   for x in range(n):
      print(trow)
      trow=[left+right for left,right in zip(trow+y, y+trow)]
    
  
def main():
    terms=int(input("Number of terms:"))
    PascalTriangle(terms)

if __name__=="__main__":
    main()
