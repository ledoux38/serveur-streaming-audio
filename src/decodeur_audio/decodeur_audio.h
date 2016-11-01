#ifndef DECODEUR_AUDIO_H
#define DECODEUR_AUDIO_H

#include"../define_serveur_client.h"

class decodeur_audio
{
public:
    decodeur_audio(opus_int32 frequence_opus=FREQUENCE_SAMPLE_OPUS,int cannaux=2);
    ~decodeur_audio();
    int get_error_decodeur_audio() const;
    OpusDecoder& get_decodeur_audio()const;
    int decodage_donnee_audio(const unsigned char*donnee_audio,opus_int32 taille_donnee_audio, opus_int16 *donnee_audio_decoder, int decode_fec );

protected:

private:
    int m_erreur;
   OpusDecoder* m_decodeur;
};


#endif//DECODEUR_AUDIO_H
