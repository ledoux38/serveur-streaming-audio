#ifndef ENCODEUR_AUDIO_H
#define ENCODEUR_AUDIO_H

#include "../define_serveur_client.h"
////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The encodeur_audio class
///encodeur_audio est un code tiré de la librairie opus_codec(OpusEncoder) qui est une structure ecrite en C
////////////////////////////////////////////////////////////////////////////////////////////

class encodeur_audio
{
public:
   encodeur_audio(unsigned int cannaux=2,opus_int32 frequence_opus=FREQUENCE_SAMPLE_OPUS,int application=APPLICATION);
   ~encodeur_audio();
   int get_encodeur_erreur()const;
   OpusEncoder &get_encodeur()const;
   opus_int32 encodage_donnee_audio(const opus_int16* donnee_audio,int taille_donnee_audio,unsigned char *donnee_audio_encoder,opus_int32	taille_donnee_audio_max);

protected:

private:
   int m_error;
      OpusEncoder* m_encodeur;
};







#endif //ENCODEUR_AUDIO_H
