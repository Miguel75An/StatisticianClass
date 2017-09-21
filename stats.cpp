
// Provided by:   MIGUEL DOMINGUEZ


#include "stats.h"
#include <cassert>
namespace main_savitch_2C
{
   statistician::statistician()
   {
      count = 0;
	  total = 0;
   }

   void statistician::next(double r)
   {
      if(count == 0)
	  {
	     tinyest = r;
		 largest = r;
	  }
	  
	  count++;
	  total += r;
	  
	  if(r > largest)
	  {
	     largest = r;
	  }
	  
	  if( r < tinyest)
	  {
	     tinyest = r;
	  }
   }

   void statistician::reset()
   {
      count = 0;
	  total = 0;
   }

   int statistician::length() const
   {
      return count;
   }

   double statistician::sum() const
   {
      return total;
   }

   double statistician::mean() const
   {
      assert(count);
      return total/count;
   }

   double statistician::minimum() const
   {
      assert(count);
	  return tinyest;
   }

   double statistician::maximum() const
   {
      assert(count);
	  return largest;
   }

   statistician operator +(const statistician& s1, const statistician& s2)
   {
      if(s1.count == 0)
	  {
	     return s2;
	  }
	  else if(s2.count == 0)
	  {
	     return s1;
	  }
	  else
	  {
         statistician s3;
	     s3.count = s1.count + s2.count;
	     s3.total = s1.total + s2.total;
	  
	     if(s1.tinyest < s2.tinyest)
	     {
	        s3.tinyest = s1.tinyest;
	     }
	     else
	     {
	        s3.tinyest = s2.tinyest;
	     }
	  
	     if(s1.largest > s2.largest)
	     {
	        s3.largest = s1.largest;
	     }
	     else
	     {
	        s3.largest = s2.largest;
	     }
	  
	     return s3;
	  }
   }

   statistician operator *(double scale, const statistician& s)
   {
      if(s.count == 0)
	  {
	     return s;
	  }
	  else
	  {	  
         statistician s3;
	     s3.count = s.count;
	     s3.total = scale*s.total;
		 if(scale < 0)
		 {
		    s3.tinyest = scale*s.largest;
			s3.largest = scale*s.tinyest;
		 }
		 else
		 {  
	        s3.tinyest = scale*s.tinyest;
	        s3.largest = scale*s.largest;
		 }
	  
	  return s3;
	  }
   } 

   bool operator ==(const statistician& s1, const statistician& s2)
   {
      if(s1.length() == 0 && s2.length() == 0)
	  {
	     return true;
	  }
	  else if(s1.length() == s2.length())
	  {
	     if(s1.mean() == s2.mean() )
		 {
		    if(s1.sum() == s2.sum() )
			{
			   if(s1.minimum() == s2.minimum() )
			   {
			      if(s1.maximum() == s2.maximum() )
				  {
				     return true;
				  }
				  else
				  {
				     return false;
				  }
			   }
			   else
			   {
			      return false;
			   }
			}
			else
			{
			   return false;
			}
		 }
		 else
		 {
		    return false;
		 }
	  }
	  else
	  {
	     return false;
	  }
   } 

}










