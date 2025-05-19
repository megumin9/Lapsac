//https://github.com/EddyRivasLab/infernal/commit/2c8326281f4942f9472e7eb73b7e79234a12f338

// Violation of Anti-Reflexivity

int compare_8(const void *vh1, const void *vh2) 
{
  CM_HIT *h1 = *((CM_HIT **) vh1);  /* don't ask. don't change. Don't Panic. */
  CM_HIT *h2 = *((CM_HIT **) vh2);
 
  if      (h1->evalue > h2->evalue) return  1; /* first key, E-value, low to high */
  else if (h1->evalue < h2->evalue) return -1;
  else { 
    if      (h1->score < h2->score) return  1; /* second key, bit score, high to low */
    else if (h1->score > h2->score) return -1;
    else {
      if      (h1->seq_idx > h2->seq_idx) return  1; /* second key, seq_idx (unique id for sequences), low to high */
      else if (h1->seq_idx < h2->seq_idx) return -1;
      else {
 	      if      (h1->start > h2->start) return  1; /* third key, start position, low to high */
 	      else if (h1->start < h2->start) return -1;
 	      else                            return  (h1->pass_idx < h2->pass_idx ? 1 : -1 ); /* fourth key, pass_idx, high to low */
      }
    }
  }
}